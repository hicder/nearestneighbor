CC = g++
CFLAGS = -c -g -O0 -std=c++11 -I/usr/local/include -Wno-deprecated-register -MMD -MP
LINKER = g++ -L/usr/local/lib -lcgal -lgmp -lmpfr
TESTLDFLAGS = -L/usr/local/lib -lgtest -lpthread -lcgal -lgmp -lmpfr
TESTCFLAGS = -I/usr/local/include -std=c++11

OBJ= main.o Plane.o Line.o Subset.o VerticalRayDS.o VerticalRay.o Cutting.o Point.o Utils.o Cell.o
nn: $(OBJ)
	$(LINKER) $(OBJ) -o nn

-include $(OBJ:.o=.d)

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o nn planetest UtilsTest

all: nn

.PHONY: clean all

test: Plane.o Utils.o
	$(LINKER) $(TESTCFLAGS) Utils.o Plane.o PlaneTest.cpp -o planetest $(TESTLDFLAGS)
	$(LINKER) $(TESTCFLAGS) Utils.o Plane.o UtilsTest.cpp -o UtilsTest $(TESTLDFLAGS)
	./planetest
	./UtilsTest
