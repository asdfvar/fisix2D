CPPC = g++
OBJ = list.o test.o shape.o assembly.o
INC = -I$(BASE) -I$(BASE)/list
BASE = ../..

all: $(OBJ)
	$(CPPC) $(INC) $(OBJ) -o test

shape.o: $(BASE)/shape.cpp
	$(CPPC) $(INC) $^ -c

assembly.o: $(BASE)/assembly.cpp
	$(CPPC) $(INC) $^ -c

list.o: $(BASE)/list/list.cpp
	$(CPPC) $(INC) $^ -c

test.o: test.cpp
	$(CPPC) $(INC) $^ -c

clean:
	rm $(OBJ) test
