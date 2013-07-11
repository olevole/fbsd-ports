--- lib/fuse-zip.h.orig	2013-07-11 22:20:54.000000000 +0400
+++ lib/fuse-zip.h	2013-07-11 22:21:12.000000000 +0400
@@ -86,13 +86,9 @@
 
 int fusezip_utimens(const char *path, const struct timespec tv[2]);
 
-#if ( __FreeBSD__ >= 10 )
-int fusezip_setxattr(const char *, const char *, const char *, size_t, int, uint32_t);
-int fusezip_getxattr(const char *, const char *, char *, size_t, uint32_t);
-#else
 int fusezip_setxattr(const char *, const char *, const char *, size_t, int);
+
 int fusezip_getxattr(const char *, const char *, char *, size_t);
-#endif
 
 int fusezip_listxattr(const char *, char *, size_t);
 
