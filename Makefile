all:	smoof.o
	g++ -o main smoof.o main.cpp 'pkg-config --cflags --libs opencv'
smoof.o:
	g++ -c smoof.cpp
clean:
	rm *.o main
run:
	./main