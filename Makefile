CPPC = g++
INC = -I. -Ilist -Idrawings
FLAGS = -Wall -O3
LINK = -lm -lGL -lGLU -lglut

OBJ = main.o shape.o list.o gettime.o \
      draw_circle.o fisix.o

EXE = main

PROG: $(OBJ)
	$(CPPC) $(FLAGS) $(INC) $(OBJ) -o $(EXE) $(LINK)

all: $(PROG)

clean:
	rm $(OBJ) $(EXE)

list.o: list/list.cpp
	$(CPPC) $(INC) $^ -c

main.o: main.cpp
	$(CPPC) $(INC) $^ -c

gettime.o: gettime.cpp
	$(CPPC) $^ -c

draw_circle.o: drawings/draw_circle.cpp
	$(CPPC) $^ -c

fisix.o: fisix.cpp
	$(CPPC) $(INC) $^ -c

%.o: %.cpp
	$(CPPC) $^ -c
