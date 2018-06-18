main : main.o bintree.o
	gcc main.o bintree.o -o main
	./main
main.o : main.c bintree.h
	gcc -c main.c
bintree.o : bintree.c bintree.h
	gcc -c bintree.c

clean :
	-rm *.o
	-rm main