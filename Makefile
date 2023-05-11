CC=gcc
CFLAGS=-I include -o example.out 
CLIBS=-lm

make: 
	$(CC) $(CFLAGS) src/main.c src/image_maker.c src/ray_trace.c src/vector3f.c src/vector2f.c $(CLIBS)