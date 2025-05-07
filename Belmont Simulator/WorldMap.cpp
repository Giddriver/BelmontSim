#pragma once
#include "WorldMap.h"
#include <iostream>

void WorldMap::displayMapArea(int minY, int maxY, int minX, int maxX, const Coordinate& playerPos) const {
    for (int y = maxY; y >= minY; --y) {
        for (int x = minX; x <= maxX; ++x) {
            Coordinate coord(y, x);
            const Node* node = getNode(coord);
            if (coord == playerPos) {
                std::cout << "@ ";
            }
            else if (node) {
                switch (node->terrain) {
                case TerrainType::Village: std::cout << "V "; break;
                case TerrainType::City:    std::cout << "C "; break;
                case TerrainType::Forest:  std::cout << "F "; break;
                case TerrainType::Cave:    std::cout << "^ "; break;
                case TerrainType::Castle:  std::cout << "K "; break;
                case TerrainType::Town:    std::cout << "T "; break;
                case TerrainType::Road:    std::cout << "# "; break;
                default:                   std::cout << "? "; break;
                }
            }
            else {
                std::cout << ". ";
            }
        }
        std::cout << "\n";
    }
}

