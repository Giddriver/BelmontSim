#include "WorldGen.h"
#include <vector>
#include <cmath>
#include <algorithm>
#include <random>

void placeForest(WorldMap& map, const Coordinate& center, int size, const std::string& name) {
    int radius = std::max(1, size / 4);
    for (int dy = -radius; dy <= radius; ++dy) {
        for (int dx = -radius; dx <= radius; ++dx) {
            Coordinate pos(center.y + dy, center.x + dx);
            map.addNode(pos, TerrainType::Forest, name);
        }
    }
}

void placeVillage(WorldMap& map, const Coordinate& location, const std::string& name) {
    map.addNode(location, TerrainType::Village, name);
}

void placeCave(WorldMap& map, const Coordinate& location, const std::string& name) {
    map.addNode(location, TerrainType::Cave, name);
}

void placeCity(WorldMap& map, const Coordinate& location, const std::string& name) {
    map.addNode(location, TerrainType::City, name);
}

void placeTown(WorldMap& map, const Coordinate& location, const std::string& name) {
    map.addNode(location, TerrainType::Town, name);
}

void placeCastle(WorldMap& map, const Coordinate& location, const std::string& name) {
    map.addNode(location, TerrainType::Castle, name);
}

void placeRoad(WorldMap& map, const Coordinate& from, const Coordinate& to) {
    int y = from.y;
    int x = from.x;
    while (y != to.y || x != to.x) {
        map.addNode({ y, x }, TerrainType::Road, "Road");
        if (x < to.x) ++x;
        else if (x > to.x) --x;
        else if (y < to.y) ++y;
        else if (y > to.y) --y;
    }
    map.addNode(to, TerrainType::Road, "Road");
}

void setupWorld(WorldMap& map) {
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> offset(-5, 5);

    Coordinate city = { 8, 8 };
    placeCity(map, city, "Ebonreach");

    std::vector<Coordinate> towns = {
        {-8, -8}, // Southwest
        {-8, 8},  // Northwest
        {8, -8}   // Southeast (but reserved for castle, shift town)
    };
    placeTown(map, towns[0], "Frostmere");
    placeTown(map, towns[1], "Brighthollow");
    placeTown(map, { 6, -6 }, "Duskport");

    std::vector<Coordinate> villages = {
        {-4, -2}, {-2, 3}, {0, -5}, {4, 1}, {-6, 6}, {3, -3}
    };
    for (int i = 0; i < villages.size(); ++i) {
        placeVillage(map, villages[i], "Village " + std::to_string(i + 1));
    }

    Coordinate castle = { 9, -9 };
    placeCastle(map, castle, "Blackspire Keep");

    std::vector<Coordinate> caves;
    while (caves.size() < 4) {
        Coordinate c = { offset(rng), offset(rng) };
        bool far_enough = true;
        for (const auto& other : caves) {
            int dy = c.y - other.y, dx = c.x - other.x;
            if (std::sqrt(dx * dx + dy * dy) < 5) {
                far_enough = false;
                break;
            }
        }
        if (far_enough) caves.push_back(c);
    }
    for (int i = 0; i < caves.size(); ++i) {
        placeCave(map, caves[i], "Cave " + std::to_string(i + 1));
    }

    // Connect city to 4 closest settlements
    std::vector<Coordinate> settlements = towns;
    settlements.insert(settlements.end(), villages.begin(), villages.end());
    std::sort(settlements.begin(), settlements.end(), [&](const Coordinate& a, const Coordinate& b) {
        int da = std::pow(city.x - a.x, 2) + std::pow(city.y - a.y, 2);
        int db = std::pow(city.x - b.x, 2) + std::pow(city.y - b.y, 2);
        return da < db;
        });
    for (int i = 0; i < 4 && i < settlements.size(); ++i) {
        placeRoad(map, city, settlements[i]);
    }

    // Fill rest of map with forest (basic 40x40 centered around origin)
    for (int y = -20; y <= 20; ++y) {
        for (int x = -20; x <= 20; ++x) {
            Coordinate c = { y, x };
            if (!map.getNode(c)) {
                map.addNode(c, TerrainType::Forest, "The Wilds");
            }
        }
    }
}
