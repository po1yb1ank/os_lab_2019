CC=gcc
CFLAGS=-pthread -I.

client : 
	$(CC) client.c getNextLine.c strsplit.c -o client $(CFLAGS)
server :
	$(CC) server.c -o server $(CFLAGS)
clean :
	rm server client
all : client server 
