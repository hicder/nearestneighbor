CC = g++
CFLAGS = -c -g -O0 -Wall -Werror -std=c++11
LINKER = g++
TESTLDFLAGS = -L/usr/local/lib -lgtest -lpthread
TESTCFLAGS = -I/usr/local/include -std=c++11

nn: main.o Plane.o Line.o Subset.o VerticalRayDS.o VerticalRay.o Cutting.o Point.o Utils.o Cell.o
	$(LINKER) main.o Plane.o Line.o Subset.o VerticalRayDS.o VerticalRay.o Cutting.o Point.o Utils.o Cell.o -o nn
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
Cutting.o:
	$(CC) $(CFLAGS) Cutting.cpp
Point.o:
	$(CC) $(CFLAGS) Point.cpp
Utils.o:
	$(CC) $(CFLAGS) Utils.cpp
Cell.o:
	$(CC) $(CFLAGS) Cell.cpp
clean:
	-rm -f *.o nn planetest

.PHONY: nn test clean all

test: Plane.o Utils.o
	$(LINKER) $(TESTCFLAGS) Plane.o PlaneTest.cpp -o planetest $(TESTLDFLAGS)
	$(LINKER) $(TESTCFLAGS) Utils.o UtilsTest.cpp -o UtilsTest $(TESTLDFLAGS)
	./planetest
	./UtilsTest
