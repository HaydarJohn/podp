all:
	g++ raycaster.cpp $$(pkg-config --libs glut opengl glu) $$(pkg-config --cflags glut opengl glu)