//
// Created by KAVOSH on 4/2/2024.
//
#ifndef INC_15PUZZLE3ENGINE_NODEPUZ_HPP
#define INC_15PUZZLE3ENGINE_NODEPUZ_HPP
#include <cstdint>
#include <array>
#include "tracker.hpp"

struct Pos{
    int r;
    int c;
};

class NodePuz{
public:

    static constexpr int MAX_ROWS {3};
    static constexpr int MAX_COLUMNS {3};
    static constexpr int MAX_ALL{MAX_ROWS * MAX_COLUMNS};
    static constexpr int HOLE{0};

    NodePuz(std::int32_t nodeConfig, const MoveTracker& mv, int depth);

    NodePuz(const NodePuz& other);
    NodePuz(NodePuz&& other) noexcept;

    NodePuz& operator=(const NodePuz& other);
    NodePuz& operator=(NodePuz&& other) noexcept;

    friend bool operator==(const NodePuz& np, std::int32_t other);
    friend bool operator==(const NodePuz& np, const NodePuz& other);
    friend std::ostream& operator<<(std::ostream& out, const NodePuz& np);

    [[nodiscard]] int at(int i, int j) const;
    bool move(const MoveUnit& mu);


private:

    [[nodiscard]] Pos deterHolePos() const;
    void set(int i, int j, int v);

    std::int32_t board;
    MoveTracker moves;
    Pos hole_pos;
    int depth;
};

#endif //INC_15PUZZLE3ENGINE_NODEPUZ_HPP
