CC = g++

LD = g++

CCFLAGS = -g -Wall  -std=c++17

LDFLAGS =

testcmp: testcmp.o mycomplex.o
	$(LD) $(LDFLAGS) -o testcmp testcmp.o mycomplex.o

testcmp.o: testcmp.cpp mycomplex.h
	$(CC)  -c testcmp.cpp

mycomplex.o: mycomplex.cpp mycomplex.h
	$(CC) -c mycomplex.cpp

clean:
	del -f *.o testcmp