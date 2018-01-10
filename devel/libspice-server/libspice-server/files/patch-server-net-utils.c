--- server/net-utils.c.bak	2017-09-12 12:00:11.000000000 +0000
+++ server/net-utils.c	2018-01-10 22:13:54.224347000 +0000
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
@@ -30,6 +33,10 @@
 #include <common/log.h>
 
 #include "net-utils.h"
+
+#if !defined(SOL_TCP) && defined(IPPROTO_TCP)
+#define SOL_TCP IPPROTO_TCP
+#endif
 
 /**
  * red_socket_set_keepalive:
