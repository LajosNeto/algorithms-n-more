main : main.o queue.o
	gcc main.o queue.o -o main
	./main
main.o : main.c queue.h
	gcc -c main.c
queue.o : queue.c queue.h
	gcc -c queue.c

clean:
	-rm *.o
	-rm main