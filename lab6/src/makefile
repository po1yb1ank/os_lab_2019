CC=gcc
CFLAGS=-pthread -I. -L. -lmod

libmodulo :
	$(CC) -c multmodulo.c
	ar rcs libmod.a multmodulo.o		
client : 
	$(CC) client.c getNextLine.c strsplit.c -o client $(CFLAGS)
server :
	$(CC) server.c -o server $(CFLAGS)
clean :
	rm server client multmodulo.o libmod.a
all : libmodulo client server 
