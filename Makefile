CPPC = g++
OBJ = main.o shape.o list.o
EXE = main

all: $(OBJ)
	$(CPPC) $(OBJ) -o $(EXE)

clean:
	rm $(OBJ) $(EXE)

%.o: %.cpp
	$(CPPC) $^ -c