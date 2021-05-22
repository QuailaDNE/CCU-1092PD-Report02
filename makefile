all: main.c BST.o BinarySearch.o Array.o LinkedList.o Hash.o
	gcc main.c BST.o BinarySearch.o Array.o LinkedList.o Hash.o -o main

BST.o: BST.c BST.h
	gcc -c BST.c -o BST.o

BinarySearch.o : BinarySearch.c BinarySearch.h
	gcc -c BinarySearch.c -o BinarySearch.o

Array.o : Array.c Array.h
	gcc -c Array.c -o Array.o

LinkedList.o : LinkedList.c LinkedList.h
	gcc -c LinkedList.c -o LinkedList.o

Hash.o : Hash.c Hash.h
	gcc -c Hash.c -o Hash.o

clean:
	rm -f BST.o BinarySearch.o Array.o LinkedList.o Hash.o main