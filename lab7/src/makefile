CC=gcc
CFLAGS=-pthread -I.

tcpclient : 
	$(CC) tcpclient.c -o tcpclient $(CFLAGS)
tcpserver :
	$(CC) tcpserver.c -o tcpserver $(CFLAGS)
udpclient : 
	$(CC) udpclient.c -o udpclient $(CFLAGS)
udpserver :
	$(CC) udpserver.c -o udpserver $(CFLAGS)
all : tcpclient tcpserver udpclient udpserver
clean :
	rm tcpclient tcpserver udpclient udpserver
