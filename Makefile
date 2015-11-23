all: main

main: main.o
	g++ main.o -o test

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -rf *.o test
