#include "GameplayUtils.h"
#include "Node.h"  // this brings in the definition of TerrainType

bool canSearchLibrary(TerrainType terrain) {
    return terrain == TerrainType::City || terrain == TerrainType::Town;
}

bool canTalkToPeople(TerrainType terrain) {
    return terrain == TerrainType::City || terrain == TerrainType::Town || terrain == TerrainType::Village;
}