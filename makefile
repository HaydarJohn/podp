LIBS = -lSDL2 -lSDL2main

all: src/*.cpp
	g++ src/*.cpp -o build/PODP ${LIBS} -Wall

run:
	./build/PODP

clear:
	rm program
