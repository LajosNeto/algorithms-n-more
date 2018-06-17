main : main.o stackcpp.o
	g++ main.o stackcpp.o -o main
	./main
main.o : main.cpp stackcpp.h
	g++ -c main.cpp
linkedlist.o: stackcpp.cpp stackcpp.h
	g++ -c stackcpp.cpp

clean:
	-rm *.o
	-rm main