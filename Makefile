GCC = gcc -Wall -Werror

.PHONY: clean 

all: build libs default

libs: libs/libadd.so libs/libsub.so libs/libdiv.so libs/libmul.so

default: mycomplex

mycomplex: src/main.c src/mycomplex.h
	$(GCC) src/main.c -o mycomplex -ldl
		
libs/libadd.so: build/add.o
	$(GCC) -shared -o libs/libadd.so build/add.o

libs/libsub.so: build/sub.o
	$(GCC) -shared -o libs/libsub.so build/sub.o

libs/libdiv.so: build/div.o
	$(GCC) -shared -o libs/libdiv.so build/div.o

libs/libmul.so: build/mul.o
	$(GCC) -shared -o libs/libmul.so build/mul.o

build/add.o: src/add.c src/mycomplex.h
	$(GCC) -fPIC -c src/add.c -o build/add.o

build/sub.o: src/sub.c src/mycomplex.h
	$(GCC) -fPIC -c src/sub.c -o build/sub.o

build/mul.o: src/mul.c src/mycomplex.h
	$(GCC) -fPIC -c src/mul.c -o build/mul.o

build/div.o: src/div.c src/mycomplex.h
	$(GCC) -fPIC -c src/div.c -o build/div.o

build:
	mkdir build
	mkdir libs

clean: 
	rm -rf build libs mycomplex
