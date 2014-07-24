CPPC = g++
INC = -I./list -I.
OBJ = main.o shape.o list.o
EXE = main

all: $(OBJ)
	$(CPPC) $(INC) $(OBJ) -o $(EXE)

clean:
	rm $(OBJ) $(EXE)

list.o: list/list.cpp
	$(CPPC) $(INC) $^ -c

main.o: main.cpp list/list.h
	$(CPPC) $(INC) $^ -c

%.o: %.cpp
	$(CPPC) $^ -c
