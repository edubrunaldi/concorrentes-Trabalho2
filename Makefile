all:	smoof.o
	g++ -o main smoof.o main.cpp
smoof.o:
	g++ -c smoof.cpp
clean:
	rm *.o main
run:
	./main