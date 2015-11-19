CC = g++
LINKER = g++
CFLAGS = -I/usr/local/include
LDFLAGS = -L/usr/local/lib -lgtest

test:
	$(LINKER) $(CFLAGS) $(LDFLAGS) PlaneTest.cpp -o planetest
	./planetest
clean:
	-rm -f planetest *.o
