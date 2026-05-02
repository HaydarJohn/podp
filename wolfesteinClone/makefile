all:
	g++ *.cpp *.c \
	-I libs/include \
	./libs/libglfw3.a \
	-framework OpenGL \
    -framework Cocoa \
    -framework IOKit \
    -framework CoreVideo \
	-o test.out
run:
	./test.out