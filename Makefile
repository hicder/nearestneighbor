CC = g++
CFLAGS = -c -g -O0 -Wall -Werror
LINKER = g++

nn: main.o
	$(LINKER) main.o -o nn
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp
clean:
	-rm -f *.o nn
