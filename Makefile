CC=gcc
CFLAGS=-I include -o render.out 
CLIBS=-lm

make: 
	$(CC) $(CFLAGS) src/main.c src/image_maker.c src/render.c src/vector3f.c src/vector2f.c $(CLIBS)