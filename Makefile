CC = g++
CFLAGS = -c -g -O0 -std=c++11 -I/usr/local/include -Wno-deprecated-register
LINKER = g++ -L/usr/local/lib -lcgal -lgmp -lmpfr
TESTLDFLAGS = -L/usr/local/lib -lgtest -lpthread -lcgal -lgmp -lmpfr
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
	$(LINKER) $(TESTCFLAGS) Utils.o Plane.o PlaneTest.cpp -o planetest $(TESTLDFLAGS)
	$(LINKER) $(TESTCFLAGS) Utils.o Plane.o UtilsTest.cpp -o UtilsTest $(TESTLDFLAGS)
	./planetest
	./UtilsTest
