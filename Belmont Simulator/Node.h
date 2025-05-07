#pragma once
#ifndef NODE_H
#define NODE_H

#include <string>
#include "Coordinate.h"

enum class TerrainType {
    Empty,
    Village,
    City,
    Forest,
    Cave,
    Castle,
    Road,
    River,
    Town
};

struct Node {
    Coordinate coord;
    TerrainType terrain;
    std::string name; // Optional, e.g., "Windfall Village"

    // Default constructor
    Node() : coord(0, 0), terrain(TerrainType::Empty), name("") {}

    // Parameterized constructor
    Node(Coordinate c, TerrainType t = TerrainType::Empty, std::string n = "")
        : coord(c), terrain(t), name(n) {
    }
};


#endif
