CC=gcc
FLAGS= -Wall -g

all:frequency 

frequency:main.c node.c 
	$(CC) $(FLAGS) main.c node.c -o frequency

main.o:main.c node.h
	$(CC) $(FLAGS) -c main.c	

clean:
	rm -f *.o *.a *.so frequency
