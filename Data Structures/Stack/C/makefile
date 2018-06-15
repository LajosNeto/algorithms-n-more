main : main.o stack.o
	gcc main.o stack.o -o main
	./main
main.o : main.c stack.h
	gcc -c main.c
stack.o : stack.c stack.h
	gcc -c stack.c

clean:
	-rm *.o
	-rm main