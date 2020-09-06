--- src/Common/MemoryStatisticsOS.cpp.orig	2020-08-31 16:22:57 UTC
+++ src/Common/MemoryStatisticsOS.cpp
@@ -1,7 +1,13 @@
-#if defined(OS_LINUX)
-
 #include <sys/types.h>
 #include <sys/stat.h>
+
+#ifdef OS_FREEBSD
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#include <sys/user.h>
+#include <libprocstat.h>
+#endif
+
 #include <fcntl.h>
 #include <unistd.h>
 #include <cassert>
@@ -11,9 +17,10 @@
 #include <Common/Exception.h>
 #include <IO/ReadBufferFromMemory.h>
 #include <IO/ReadHelpers.h>
-#include <common/logger_useful.h>
 
 
+
+
 namespace DB
 {
 
@@ -23,21 +30,40 @@ namespace ErrorCodes
     extern const int CANNOT_OPEN_FILE;
     extern const int CANNOT_READ_FROM_FILE_DESCRIPTOR;
     extern const int CANNOT_CLOSE_FILE;
+#ifdef OS_FREEBSD
+    extern const int CANNOT_ALLOCATE_MEMORY;
+#endif
 }
 
+#ifndef OS_FREEBSD
 static constexpr auto filename = "/proc/self/statm";
 static constexpr size_t PAGE_SIZE = 4096;
+#endif
 
 MemoryStatisticsOS::MemoryStatisticsOS()
 {
+#ifdef OS_FREEBSD
+    pstat = ::procstat_open_sysctl();
+    if (NULL == pstat)
+    {
+        throwFromErrno("Cannot open sysctl", ErrorCodes::CANNOT_ALLOCATE_MEMORY);
+    }
+#else
     fd = ::open(filename, O_RDONLY | O_CLOEXEC);
 
     if (-1 == fd)
         throwFromErrno("Cannot open file " + std::string(filename), errno == ENOENT ? ErrorCodes::FILE_DOESNT_EXIST : ErrorCodes::CANNOT_OPEN_FILE);
+#endif
 }
 
 MemoryStatisticsOS::~MemoryStatisticsOS()
 {
+#ifdef OS_FREEBSD
+    if (NULL != pstat)
+    {
+        ::procstat_close(pstat);
+    }
+#else
     if (0 != ::close(fd))
     {
         try
@@ -51,12 +77,43 @@ MemoryStatisticsOS::~MemoryStatisticsOS()
             DB::tryLogCurrentException(__PRETTY_FUNCTION__);
         }
     }
+#endif
 }
 
 MemoryStatisticsOS::Data MemoryStatisticsOS::get() const
 {
     Data data;
 
+#ifdef OS_FREEBSD
+    size_t pagesize = ::getpagesize();
+    unsigned int count = 0;
+
+    struct kinfo_proc *kp;
+    struct kinfo_vmentry *kve;
+
+    kp = ::procstat_getprocs(pstat, KERN_PROC_PID, ::getpid(), &count);
+    if (NULL == kp)
+    {
+        throwFromErrno("Cannot get proc info", ErrorCodes::CANNOT_ALLOCATE_MEMORY);
+    }
+
+    kve = ::procstat_getvmmap(pstat, kp, &count);
+    if (NULL == kve)
+    {
+        ::procstat_freeprocs(pstat, kp);
+        throwFromErrno("Cannot get vmmap info", ErrorCodes::CANNOT_ALLOCATE_MEMORY);
+    }
+
+    data.virt = kp->ki_size;
+    data.resident =  kp->ki_rssize * pagesize;
+    data.shared = (kp->ki_rssize - kve->kve_private_resident) * pagesize;
+    data.code = kp->ki_tsize * pagesize;
+    data.data_and_stack = (kp->ki_dsize + kp->ki_ssize) * pagesize;
+
+    ::procstat_freevmmap(pstat, kve);
+    ::procstat_freeprocs(pstat, kp);
+#else
+
     constexpr size_t buf_size = 1024;
     char buf[buf_size];
 
@@ -98,10 +155,8 @@ MemoryStatisticsOS::Data MemoryStatisticsOS::get() con
     data.shared *= PAGE_SIZE;
     data.code *= PAGE_SIZE;
     data.data_and_stack *= PAGE_SIZE;
-
+#endif
     return data;
 }
 
 }
-
-#endif
