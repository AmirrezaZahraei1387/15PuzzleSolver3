//
// Created by KAVOSH on 4/2/2024.
//
#ifndef INC_15PUZZLE3ENGINE_NODEPUZ_HPP
#define INC_15PUZZLE3ENGINE_NODEPUZ_HPP
#include <cstdint>
#include <array>
#include "tracker.hpp"

// representing a particular position of the table
struct Pos{
    int r;
    int c;

    friend bool operator==(const Pos& p1, const Pos& p2);
};


class NodePuz{
public:

    static constexpr int MAX_ROWS {3};
    static constexpr int MAX_COLUMNS {3};

    static constexpr int MAX_ALL{MAX_ROWS * MAX_COLUMNS}; // max number of tiles
    static constexpr int HOLE{0}; // home tile is represented with 0

    NodePuz(std::int32_t nodeConfig, const MoveTracker& mv, int depth);

    NodePuz(const NodePuz& other);
    NodePuz(NodePuz&& other) noexcept;

    NodePuz& operator=(const NodePuz& other);
    NodePuz& operator=(NodePuz&& other) noexcept;

    friend bool operator==(const NodePuz& np, std::int32_t other);
    friend bool operator==(const NodePuz& np, const NodePuz& other);
    friend std::ostream& operator<<(std::ostream& out, const NodePuz& np);

    // returns the tile at the given position raises exception if
    // the position is invalid
    [[nodiscard]] int at(int i, int j) const;
    bool move(const MoveUnit& mu);
    [[nodiscard]] const MoveTracker& getMoves() const;
    [[nodiscard]] std::int32_t getConfig() const;
    [[nodiscard]] int getDepth() const;
    Pos find(int k) const;

    void inc_depth();

    static bool isvalid(const Pos& pos);
private:
    [[nodiscard]] Pos deterHolePos() const;

    // sets a particular tile to a value
    // mainly used for moving the home tile
    void set(int i, int j, int v);

    std::int32_t board;
    MoveTracker moves;
    Pos hole_pos;
    int depth;
};

NodePuz applyMoveTracker(const NodePuz& np, const MoveTracker& mvt);
#endif //INC_15PUZZLE3ENGINE_NODEPUZ_HPP
