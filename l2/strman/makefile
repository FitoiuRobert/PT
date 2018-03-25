all:
	gcc -Wall -O3 -pedantic -c -o libstr.o libstr.c
	gcc -Wall -O3 -pedantic -c main.c -o main.o
	ar rcs libstr.a libstr.o
	gcc -Wall -O3 -pedantic -o main.x main.o -L. -lstr
	