CC = g++
CFLAGS = -c -g -O0 -Wall -Werror -std=c++11
LINKER = g++
TESTLDFLAGS = -L/usr/local/lib -lgtest -lpthread
TESTCFLAGS = -I/usr/local/include

nn: main.o Plane.o Line.o Subset.o VerticalRayDS.o VerticalRay.o
	$(LINKER) main.o Plane.o Line.o Subset.o VerticalRayDS.o VerticalRay.o -o nn
main.o:
	$(CC) $(CFLAGS) main.cpp
Plane.o:
	$(CC) $(CFLAGS) Plane.cpp
Line.o:
	$(CC) $(CFLAGS) Line.cpp
Subset.o:
	$(CC) $(CFLAGS) Subset.cpp
VerticalRayDS.o:
	$(CC) $(CFLAGS) VerticalRayDS.cpp
VerticalRay.o:
	$(CC) $(CFLAGS) VerticalRay.cpp
clean:
	-rm -f *.o nn planetest

.PHONY: nn test clean all

test: plane.o
	$(LINKER) $(TESTCFLAGS) plane.o PlaneTest.cpp -o planetest $(TESTLDFLAGS)
	./planetest
