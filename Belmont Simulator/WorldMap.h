#ifndef WORLDMAP_H
#define WORLDMAP_H

#include <map>
#include "Node.h"

class WorldMap {
private:
    std::map<Coordinate, Node> nodes;

public:
    void addNode(const Coordinate& coord, TerrainType type, const std::string& name = "") {
        nodes[coord] = Node(coord, type, name);
    }

    const Node* getNode(const Coordinate& coord) const {
        auto it = nodes.find(coord);
        if (it != nodes.end()) return &it->second;
        return nullptr;
    }

	TerrainType getTerrainAt(const Coordinate& coord) const {
		const Node* node = getNode(coord);
		if (node) return node->terrain;
		return TerrainType::Empty; // Default to empty if not found
	}

    void displayMapArea(int minY, int maxY, int minX, int maxX, const Coordinate& playerPos) const;
};

#endif