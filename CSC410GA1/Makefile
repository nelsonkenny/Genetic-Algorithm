program: genome.o main.o
	g++ -o program genome.o main.o
genome.o: genome.h genome.cc
	g++ -c genome.cc
main.o: main.cc
	g++ -c main.cc
clean:
	rem -f *.o program
