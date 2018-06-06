main : main.o linkedlist.o
	g++ main.o linkedlist.o -o main
	./main
main.o : main.cpp linkedlist_cpp.h
	g++ -c main.cpp
linkedlist.o: linkedlist.cpp linkedlist_cpp.h
	g++ -c linkedlist.cpp

clean:
	-rm *.o
	-rm main