#include "game.h"
#include "WorldGen.h"
#include "GameData.h"

int main() {
    Coordinate startLocation = { 8, 8 }; // Start in Ebonreach
    Player player("Hunter", 10, 7, 8, 5, 6, startLocation);
    WorldMap world;
    setupWorld(world);

    gameLoop(player, world);
    return 0;
}