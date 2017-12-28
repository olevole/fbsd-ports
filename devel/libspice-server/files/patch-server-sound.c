--- server/sound.c.orig	2017-09-21 14:05:07.000000000 +0300
+++ server/sound.c	2017-12-27 17:43:39.803158000 +0300
@@ -22,6 +22,8 @@
 #include <fcntl.h>
 #include <errno.h>
 #include <limits.h>
+#include <sys/types.h>
+#include <netinet/in.h>
 #include <sys/socket.h>
 #include <netinet/ip.h>
 #include <netinet/tcp.h>
