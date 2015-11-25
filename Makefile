CC = g++
CFLAGS = -c -g -O0 -Wall -Werror
LINKER = g++
TESTLDFLAGS = -L/usr/local/lib -lgtest -lpthread
TESTCFLAGS = -I/usr/local/include

nn: main.o plane.o
	$(LINKER) main.o plane.o -o nn
main.o:
	$(CC) $(CFLAGS) main.cpp
plane.o:
	$(CC) $(CFLAGS) plane.cpp
clean:
	-rm -f *.o nn planetest

test: plane.o
	$(LINKER) $(TESTCFLAGS) plane.o PlaneTest.cpp -o planetest $(TESTLDFLAGS)
	./planetest
