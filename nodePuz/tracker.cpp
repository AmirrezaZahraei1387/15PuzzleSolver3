//
// Created by KAVOSH on 4/2/2024.
//
#include "tracker.hpp"

MoveUnit::MoveUnit(MoveUnit::MV m)
: mov(m){}

MoveUnit::MoveUnit()
: mov(MV::NONE){}

MoveUnit::MoveUnit(const MoveUnit &other) {this->mov = other.mov;}

MoveUnit& MoveUnit::operator=(const MoveUnit &other) {
    if(this != &other)
        this->mov = other.mov;
    return *this;
}

std::ostream &operator<<(std::ostream &out, const MoveUnit& mu){
    switch (mu.mov) {
        case MoveUnit::UP:
            out<<"UP";
            break;

        case MoveUnit::DOWN:
            out<<"DOWN";
            break;

        case MoveUnit::LEFT:
            out<<"LEFT";
            break;
        case MoveUnit::RIGHT:
            out<<"RIGHT";
            break;

        case MoveUnit::NONE:
            out<<"NONE";
            break;
    }

    return out;
}

MoveUnit::MV MoveUnit::get() const{return mov;}
void MoveUnit::set(MoveUnit::MV new_mv){mov = new_mv;}








