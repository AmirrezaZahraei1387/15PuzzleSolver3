cmake_minimum_required(VERSION 3.23)
project(15PuzzleSolver3)

set(CMAKE_CXX_STANDARD 17)

add_executable(14PuzzleSolver3 main.cpp
        nodePuz/nodePuz.cpp
        nodePuz/nodePuz.hpp
        nodePuz/tracker.hpp
        nodePuz/tracker.cpp
        solver/solver.hpp
        solver/basic_solvers.cpp
        solver/pro_solvers.cpp)
