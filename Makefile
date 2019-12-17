GCC = gcc -Wall -Werror

mycomplex: main.o mycomplex.o
	$(GCC) main.o mycomplex.o -o mycomplex

mycomplex.o: mycomplex.c mycomplex.h
	$(GCC) -c mycomplex.c -o mycomplex.o

main.o: main.c mycomplex.h
	$(GCC) -c main.c -o main.o 
