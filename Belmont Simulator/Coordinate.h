#pragma once
#include <tuple>
// Coordinate.h
#ifndef COORDINATE_H
#define COORDINATE_H

struct Coordinate {
    int y; // North (+) / South (-)
    int x; // East (+) / West (-)

    Coordinate(int y_val = 0, int x_val = 0) : y(y_val), x(x_val) {}

    bool operator==(const Coordinate& other) const {
        return y == other.y && x == other.x;
    }

    bool operator<(const Coordinate& other) const {
        return std::tie(y, x) < std::tie(other.y, other.x); // For use in std::map
    }
};

#endif