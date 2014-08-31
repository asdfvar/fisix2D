CPPC = g++
INC = -I. -Ilist -Idrawings
FLAGS = -Wall -O3
LINK = -lm -lGL -lGLU -lglut

OBJ = main.o shape.o list.o gettime.o \
      draw_circle.o fisix.o list_circle.o \
      drawings.o draw_line.o line.o

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

list_circle.o: list/list_circle.cpp
	$(CPPC) $(INC) $^ -c

shape.o: shape.cpp
	$(CPPC) $(INC) $^ -c

drawings.o: drawings/drawings.cpp
	$(CPPC) $(INC) $^ -c

draw_line.o: drawings/draw_line.cpp
	$(CPPC) $(INC) $^ -c

line.o: line.cpp
	$(CPPC) $(INC) $^ -c

%.o: %.cpp
	$(CPPC) $^ -c
