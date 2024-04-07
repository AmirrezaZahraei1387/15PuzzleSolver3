CXX := g++
CXX_FLAGS := -Wall -g

EXE_NAME := 15PuzzleSolver

VALGRIND_FLAGS := --leak-check=yes --track-origins=yes
OBJECTS := basic_solvers.o pro_solvers.o nodePuz.o tracker.o main.o


.PHONY: all
all: $(OBJECTS)
	$(CXX) $(CXX_FLAGS) -o $(EXE_NAME) $^


.PHONY: clean
clean:
	rm $(OBJECTS) $(EXE_NAME)


.PHONY: valgrind
valgrind:
	valgrind $(VALGRIND_FLAGS) ./$(EXE_NAME)


.PHONY: run
run:
	./$(EXE_NAME)


basic_solvers.o: solver/solver.hpp solver/basic_solvers.cpp
	$(CXX) $(CXX_FLAGS) -c solver/basic_solvers.cpp

pro_solvers.o: solver/solver.hpp solver/pro_solvers.cpp
	$(CXX) $(CXX_FLAGS) -c solver/pro_solvers.cpp

nodePuz.o: nodePuz/nodePuz.hpp nodePuz/nodePuz.cpp
	$(CXX) $(CXX_FLAGS) -c nodePuz/nodePuz.cpp

tracker.o: nodePuz/tracker.hpp nodePuz/tracker.cpp
	$(CXX) $(CXX_FLAGS) -c nodePuz/tracker.cpp

main.o: nodePuz/tracker.hpp solver/solver.hpp nodePuz/tracker.hpp main.cpp
	$(CXX) $(CXX_FLAGS) -c main.cpp