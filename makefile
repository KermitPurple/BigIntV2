all: main.o BigInt.o
	g++ bin/*.o -o bin/test.exe -I include
	@echo

main.o: src/main.cpp
	g++ src/main.cpp -c -o bin/main.o -I include

BigInt.o: src/BigInt.cpp
	g++ src/BigInt.cpp -c -o bin/BigInt.o -I include

clean:
	rm bin/*

new:
	mkdir bin

test: all
	bin/test.exe
