CPPC = g++
INC = -I./list -I. -Idrawings
FLAGS = -Wall -O3
LINK = -lm -lGL -lGLU -lglut

OBJ = main.o shape.o list.o gettime.o \
      draw_circle.o drawing.o processing.o

EXE = main

PROG: $(OBJ)
	$(CPPC) $(FLAGS) $(INC) $(OBJ) -o $(EXE) $(LINK)

all: $(PROG)

clean:
	rm $(OBJ) $(EXE)

drawing.o: drawing.cpp
	$(CPPC) $(INC) $^ -c

processing.o: processing.cpp
	$(CPPC) $^ -c

list.o: list/list.cpp
	$(CPPC) $(INC) $^ -c

main.o: main.cpp
	$(CPPC) $(INC) $^ -c

gettime.o: gettime.cpp
	$(CPPC) $^ -c

draw_circle.o: drawings/draw_circle.cpp
	$(CPPC) $^ -c

%.o: %.cpp
	$(CPPC) $^ -c
