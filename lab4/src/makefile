CC=gcc
CFLAGS=-I.

all : zombie memory sum

sum : parallel_sum.c utils.c
	$(CC) -pthread -o parallel_sum parallel_sum.c utils.c $(CFLAGS)

memory: process_memory.c
	$(CC) -o process_memory process_memory.c $(CFLAGS)
	
zombie : zombie.c
	$(CC) -o zombie zombie.c $(CFLAGS)

clean : 
	rm zombie.o zombie process_memory parallel_sum 
