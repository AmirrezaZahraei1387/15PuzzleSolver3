# 15PuzzleSolver3

## Goal:
The purpose of the following program is to solve 3x3 puzzles with at least
5 different ways including:

1 - DFS

2 - BFS

3 - number of tiles out of place.

4 - minimum number of moves to reach the goal state.

5 - the heuristic H.

the program asks for a starting configuration and an ending configuration
and then output the moves required to proceed to reach the goal state.

## Nodes of Search Space

Internally each node is represented by a 9 digit int32_t type to save
space during searching.

## Solvers
Solvers include

``` c++
void solveWithDFS(const NodePuz& init, const NodePuz& endto, MoveTracker& mvt);

void solveWithBFS(const NodePuz& init, const NodePuz& endto, MoveTracker& mvt);

void solveWithTilesOut(const NodePuz& init, const NodePuz& endto, MoveTracker& mvt);

void solveWithMinLitMoves(const NodePuz& init, const NodePuz& endto, MoveTracker& mvt);

void solveWithHScore(const NodePuz& init, const NodePuz& endto, MoveTracker& mvt);
```

## Compiling and Execution

To compile and run the program please use the provided makefile.

to build:
```cmd
make all
```

to run:
```cmd
make run
```

to clean up:
```
make clean
```
