--- server/red-worker.c.bak	2017-09-21 14:05:07.000000000 +0300
+++ server/red-worker.c	2017-12-27 17:53:23.512584000 +0300
@@ -28,6 +28,7 @@
 #include <unistd.h>
 #include <poll.h>
 #include <pthread.h>
+#include <pthread_np.h>
 #include <openssl/ssl.h>
 #include <inttypes.h>
 #include <glib.h>
@@ -51,6 +52,16 @@
 #define CMD_RING_POLL_RETRIES 1
 
 #define INF_EVENT_WAIT ~0
+
+int pthread_setname_np(pthread_t, const char *);
+
+
+int pthread_setname_np(pthread_t id, const char *name)
+{
+	/* this BSD function returns no error */
+	pthread_set_name_np(id, name);
+	return 0;
+}
 
 struct RedWorker {
     pthread_t thread;
