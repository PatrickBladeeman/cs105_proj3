CC = g++
CFLAGS = -Wall -Wextra -std=c++11

all: DarkZone

DarkZone: Queue.o Stack.o DarkZone.o
	$(CC) $(CFLAGS) -o DarkZone Queue.o Stack.o DarkZone.o

Queue.o: Queue.cpp Queue.h
	$(CC) $(CFLAGS) -c Queue.cpp

Stack.o: Stack.cpp Stack.h
	$(CC) $(CFLAGS) -c Stack.cpp

DarkZone.o: DarkZone.cpp Queue.h Stack.h
	$(CC) $(CFLAGS) DarkZone.cpp

clean:
	rm -f DarkZone *.o
