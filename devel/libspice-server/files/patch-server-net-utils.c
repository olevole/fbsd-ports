--- server/net-utils.c.orig	2017-09-12 15:00:11.000000000 +0300
+++ server/net-utils.c	2017-12-27 17:40:47.728516000 +0300
@@ -23,6 +23,9 @@
 #include <fcntl.h>
 #include <stdbool.h>
 #include <string.h>
+#include <sys/types.h>
+#include <arpa/inet.h>
+#include <netinet/in.h>
 #include <netinet/ip.h>
 #include <netinet/tcp.h>
 #include <sys/socket.h>
@@ -42,7 +45,7 @@
 {
     int keepalive = !!enable;
 
-    if (setsockopt(fd, SOL_SOCKET, SO_KEEPALIVE, &keepalive, sizeof(keepalive)) == -1) {
+    if (setsockopt(fd, IPPROTO_TCP, SO_KEEPALIVE, &keepalive, sizeof(keepalive)) == -1) {
         if (errno != ENOTSUP) {
             spice_printerr("setsockopt for keepalive failed, %s", strerror(errno));
             return false;
@@ -54,7 +57,7 @@
     }
 
 #ifdef HAVE_TCP_KEEPIDLE
-    if (setsockopt(fd, SOL_TCP, TCP_KEEPIDLE, &timeout, sizeof(timeout)) == -1) {
+    if (setsockopt(fd, IPPROTO_TCP, TCP_KEEPIDLE, &timeout, sizeof(timeout)) == -1) {
         if (errno != ENOTSUP) {
             spice_printerr("setsockopt for keepalive timeout failed, %s", strerror(errno));
             return false;
