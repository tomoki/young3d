CPP = g++
CFLAGS = -O2 -std=c++11 -Wall
LDFLAGS = -L/usr/lib
LIBS = -lGL -lGLU -lglut
OBJS = main.o ogl.o young.o
PROGRAM = young

all: $(PROGRAM)

$(PROGRAM):$(OBJS)
	$(CPP) $(OBJS) $(CFLAGS) $(LDFLAGS) $(LIBS) -o $(PROGRAM)

.cpp.o:
	$(CPP) $(CFLAGS) -c $<

clean:;
	rm -f *.o

PHONY: check-syntax
check-syntax:
	$(CPP) -Wall -fsyntax-only $(LDFLAGS) $(CFLAGS) $(LIBS) $(CHK_SOURCES)
