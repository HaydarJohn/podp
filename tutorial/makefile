all:
	g++ src/*.cpp src/*c -o build/program.exe -I include/ -L lib/* -lglfw3 -lGL -lX11 -lpthread -lXrandr -lXi -ldl

run:
	./build/program.exe

clean:
	rm build/*