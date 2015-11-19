CC = g++
CFLAGS = -c -g -O0 -Wall -Werror
LINKER = g++

nn: main.o plane.o
	$(LINKER) main.o plane.o -o nn
main.o:
	$(CC) $(CFLAGS) main.cpp
plane.o:
	$(CC) $(CFLAGS) plane.cpp
clean:
	-rm -f *.o nn
