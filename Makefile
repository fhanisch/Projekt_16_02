LIB=-lSDL -lGLEW -lGL
CC=c++

Projekt_16_02:
	$(CC) -o build/$@ src/*.cpp $(LIB)
