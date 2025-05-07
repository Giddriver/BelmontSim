#pragma once

#include "WorldMap.h"

void placeForest(WorldMap& map, const Coordinate& center, int size, const std::string& name);
void placeVillage(WorldMap& map, const Coordinate& location, const std::string& name);
void placeCave(WorldMap& map, const Coordinate& location, const std::string& name);
void placeCity(WorldMap& map, const Coordinate& location, const std::string& name);
void placeTown(WorldMap& map, const Coordinate& location, const std::string& name);
void placeCastle(WorldMap& map, const Coordinate& location, const std::string& name);
void placeRoad(WorldMap& map, const Coordinate& from, const Coordinate& to);
void setupWorld(WorldMap& map);