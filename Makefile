all:	smooth.o
	g++ -Wall -g -o main smooth.o main.cpp `pkg-config --libs opencv`
smooth.o:
	g++ -Wall -c smooth.cpp
clean:
	rm *.o main
run:
	./main