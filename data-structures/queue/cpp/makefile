main : main.o queuecpp.o
	g++ main.o queuecpp.o -o main
	./main
main.o : main.cpp queuecpp.h
	g++ -c main.cpp
queuecpp.o: queuecpp.cpp queuecpp.h
	g++ -c queuecpp.cpp

clean:
	-rm *.o
	-rm main