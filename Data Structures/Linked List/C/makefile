main : main.o linkedlist.o
	gcc main.o linkedlist.o -o main
main.o : main.c linkedlist.h
	gcc -c main.c
linkedlist.o : linkedlist.c linkedlist.h
	gcc -c linkedlist.c

clean:
	-rm *.o