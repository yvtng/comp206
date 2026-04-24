CC = gcc
CFLAGS =-Wall -Werror -std=c99

all: queue

queue: main.o ringbuffer.o
	$(CC) $(CFLAGS) main.o ringbuffer.o -o queue

main.o: main.c ringbuffer.h
	$(CC) $(CFLAGS) -c main.c

ringbuffer.o: ringbuffer.c ringbuffer.h
	$(CC) $(CFLAGS) -c ringbuffer.c

clean:
	rm -f *.o queue
