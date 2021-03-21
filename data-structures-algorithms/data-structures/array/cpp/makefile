main : main.o dinarray.o
	g++ main.o dinarray.o -o main
main.o : main.cpp dinarray.h
	g++ -c main.cpp
dinarray.o: dinarray.cpp dinarray.h
	g++ -c dinarray.cpp