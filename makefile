CC = clang

CFLAGS = -Wall -Wextra -pedantic

SOURCE_LIBS = -Ilib/

OBJECT_FILES = obj/*.o

OSX_OPT = -Llib/ -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL lib/libraylib.a
OSX_OUT = bin/build_osx

build_2D: obj/graphics2D.o
	$(CC) $(CFLAGS) obj/graphics2D.o src/main.c $(SOURCE_LIBS) -o "$(OSX_OUT)" $(OSX_OPT)
obj/graphics2D.o:
	$(CC) $(CFLAGS) $(SOURCE_LIBS) -c src/graphics2D.c -o obj/graphics2D.o
build_and_run2D: build_2D
	./$(OSX_OUT)
rebuild_and_run2D: clean build_and_run2D

build_3D: obj/graphics3D.o
	$(CC) $(CFLAGS) -D GRAPHICS3D obj/graphics3D.o src/main.c $(SOURCE_LIBS) -o "$(OSX_OUT)" $(OSX_OPT)
obj/graphics3D.o:
	$(CC) $(CFLAGS) $(SOURCE_LIBS) -c src/graphics3D.c -o obj/graphics3D.o
build_and_run3D: build_3D
	./$(OSX_OUT)
rebuild_and_run3D: clean build_and_run3D

clean:
	-rm ./bin/*
	-rm ./obj/*
