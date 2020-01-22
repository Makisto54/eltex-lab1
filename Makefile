GCC = gcc -Wall -Werror
OBJ = build/add.o build/sub.o build/div.o build/mul.o

.PHONY: clean 

all: build lib default

lib: libmycomplex.a

default: mycomplex

libmycomplex.a: $(OBJ)
	ar rc libmycomplex.a $(OBJ)

mycomplex: build/main.o $(OBJ)
	$(GCC) build/main.o -o mycomplex -L. -l mycomplex

build/add.o: src/add.c src/mycomplex.h
	$(GCC) -c src/add.c -o build/add.o

build/sub.o: src/sub.c src/mycomplex.h
	$(GCC) -c src/sub.c -o build/sub.o

build/mul.o: src/mul.c src/mycomplex.h
	$(GCC) -c src/mul.c -o build/mul.o

build/div.o: src/div.c src/mycomplex.h
	$(GCC) -c src/div.c -o build/div.o

build/main.o: src/main.c src/mycomplex.h
	$(GCC) -c src/main.c -o build/main.o

build:
	mkdir build

clean: 
	rm -rf build libmycomplex.a mycomplex
