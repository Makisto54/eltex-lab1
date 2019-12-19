GCC = gcc -Wall -Werror

.PHONY: clean

all: bin build default

default: bin/mycomplex

bin/mycomplex: build/main.o build/mycomplex.o
	$(GCC) build/main.o build/mycomplex.o -o bin/mycomplex

build/mycomplex.o: src/mycomplex.c src/mycomplex.h
	$(GCC) -c src/mycomplex.c -o build/mycomplex.o

build/main.o: src/main.c src/mycomplex.h
	$(GCC) -c src/main.c -o build/main.o 

bin:
	mkdir bin

build:
	mkdir build

clean:
	rm -rf bin build
