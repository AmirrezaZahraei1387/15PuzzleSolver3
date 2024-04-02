//
// Created by KAVOSH on 4/2/2024.
//
#include <exception>
#include <cmath>
#include "nodePuz.hpp"

Pos NodePuz::deterHolePos() const {
    for(int i{0}; i < MAX_ROWS; ++i)
        for(int j{0}; j < MAX_COLUMNS; ++j)
            if(at(i, j) == HOLE)
                return {i, j};
    return {-1, -1};
}

NodePuz::NodePuz(std::int32_t nodeConfig, const MoveTracker& mv, int depth)
: board(nodeConfig), moves(mv), depth(depth)
{hole_pos = deterHolePos();}

NodePuz::NodePuz(const NodePuz& other){
    this->board = other.board;
    this->depth = other.depth;
    this->moves = other.moves;
    this->hole_pos = other.hole_pos;
}

NodePuz::NodePuz(NodePuz &&other) noexcept{
    this->board = other.board;
    this->depth = other.depth;
    this->moves = std::move(other.moves);
    this->hole_pos = other.hole_pos;
}

NodePuz& NodePuz::operator=(const NodePuz& other){
    if(this != &other) {
        this->board = other.board;
        this->depth = other.depth;
        this->moves = other.moves;
        this->hole_pos = other.hole_pos;
    }

    return *this;
}

NodePuz& NodePuz::operator=(NodePuz&& other) noexcept{
    if(this != &other) {
        this->board = other.board;
        this->depth = other.depth;
        this->moves = std::move(other.moves);
        this->hole_pos = other.hole_pos;
    }

    return *this;
}


bool operator==(const NodePuz &np, std::int32_t other) {return np.board == other;}
bool operator==(const NodePuz& np, const NodePuz& other){return np.board == other.board;}

int NodePuz::at(int i, int j) const {
    if(i >= 0 && i < MAX_ROWS && j >= 0 && j < MAX_COLUMNS) {
        int index{MAX_ALL - (i * MAX_ROWS + j) - 1};
        return (board / static_cast<std::int32_t>(std::pow(10, index))) % 10;
    }

    throw std::out_of_range("index out of range at NodePuz::at");
}

bool NodePuz::move(const MoveUnit& mu) {
    /*
     * We use integer instead of enum to allow iteration
     * UP = 0,
     * DOWN = 1,
     * LEFT = 2,
     * RIGHT = 3
     */
    switch (mu.get()) {
        case MoveUnit::UP:
            if(hole_pos.r == 0) return false;
            set(hole_pos.r, hole_pos.c, at(hole_pos.r - 1, hole_pos.c));
            set(--hole_pos.r, hole_pos.c, HOLE);
            break;

        case MoveUnit::DOWN:
            if(hole_pos.r == MAX_ROWS - 1) return false;
            set(hole_pos.r, hole_pos.c, at(hole_pos.r + 1, hole_pos.c));
            set(++hole_pos.r, hole_pos.c, HOLE);
            break;

        case MoveUnit::LEFT:
            if(hole_pos.c == 0) return false;
            set(hole_pos.r, hole_pos.c, at(hole_pos.r, hole_pos.c - 1));
            set(hole_pos.r, --hole_pos.c, HOLE);
            break;

        case MoveUnit::RIGHT:
            if(hole_pos.c == MAX_COLUMNS - 1) return false;
            set(hole_pos.r, hole_pos.c, at(hole_pos.r, hole_pos.c+1));
            set(hole_pos.r, ++hole_pos.c, HOLE);
            break;
        default:
            return false;
    }
    return true;
}

void NodePuz::set(int i, int j, int v) {
    if (i >= 0 && i < MAX_ROWS && j >= 0 && j < MAX_COLUMNS) {
        int index{MAX_ALL - (i * MAX_ROWS + j)};
        int digit{(board / static_cast<std::int32_t>(std::pow(10, index))) % 10};
        board -= static_cast<std::int32_t>(std::pow(10, index))*digit;
        board += static_cast<std::int32_t>(std::pow(10, index))*v;
    }
    throw std::out_of_range("index out of range at NodePuz::at");
}

std::ostream& operator<<(std::ostream &out, const NodePuz &np) {
    out<<np.board;
    return out;
}









