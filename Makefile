CPP = g++
CFLAGS = -O2 -std=c++11 -Wall `sdl2-config --cflags`
LDFLAGS = -L/usr/lib
LIBS = -lGL -lGLU `sdl2-config --libs`
OBJS = main.o sdllib.o young.o
PROGRAM = young

all: $(PROGRAM)

$(PROGRAM):$(OBJS)
	$(CPP) $(CFLAGS) $(OBJS) $(LDFLAGS) $(LIBS) -o $(PROGRAM)

clean:;
	rm -f *.o

PHONY: check-syntax
check-syntax:
	$(CPP) -Wall -fsyntax-only $(LDFLAGS) $(CFLAGS) $(LIBS) $(CHK_SOURCES)

