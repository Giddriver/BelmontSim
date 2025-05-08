#include <iostream>
#include "game.h"
#include "encounters.h"
#include "NPCLogic.h"
#include "Library.h"
#include "NPCGenerator.h"
#include "WorldMap.h"
#include "player.h"
#include "WorldGen.h"
#include "GameplayUtils.h"

std::string terrainTypeToString(TerrainType type) {
    switch (type) {
    case TerrainType::City: return "City";
    case TerrainType::Town: return "Town";
    case TerrainType::Village: return "Village";
    case TerrainType::Forest: return "Forest";
    case TerrainType::Castle: return "Castle";
    case TerrainType::Cave: return "Cave";
    case TerrainType::Road: return "Road";
    default: return "Unknown";
    }
}

void gameLoop(Player& player, WorldMap& world) {
    bool running = true;
    std::vector<NPC> npcList = generateAllNPCs();
    std::cout << "Generated " << npcList.size() << " NPCs.\n";
    // Define a sample vampire and NPC
    VampireKnowledge vampire = { "Count Dracula", "Transylvania", "Humans", 500, {"Can turn into a bat", "Strength of 10 men"}, {}, {} };
    NPC npc = findNPC("Forest");
    TerrainType currentTerrain = world.getTerrainAt(player.position);

    while (running) {
        std::cout << "\nWhat would you like to do?\n";
        std::cout << "1. Talk to NPC\n2. Search library\n3. Explore\n4. Move\n5. View Map\n6. Quit\n> ";
        char choice;
        std::cin >> choice;

        switch (choice) {
        case '1':
            if (canTalkToPeople(currentTerrain)) {
                std::cout << "You talk to a local...\n";
                gatherSpecificKnowledge(player, vampire, npc);
            }
            else {
                std::cout << "There is no one to talk to here.\n";
            }
            break;
        case '2':
            if (canSearchLibrary(currentTerrain)) {
                std::cout << "You search the library for ancient vampire lore.\n";
                searchLibrary(player);
            }
            else {
                std::cout << "There is no library here to search.\n";
            }
            break;
        case '3':
            // You could expand this to encounter more NPCs or events
            std::cout << "You explore the area...\n";
            break;
        case '4': {
            std::cout << "Move where? (N/S/E/W): ";
            char dir;
            std::cin >> dir;

            Coordinate delta;
            switch (toupper(dir)) {
            case 'N': delta = { -1, 0 }; break;
            case 'S': delta = { 1, 0 }; break;
            case 'E': delta = { 0, 1 }; break;
            case 'W': delta = { 0, -1 }; break;
            default:
                std::cout << "Invalid direction.\n";
                continue;
            }

            Coordinate newPos = { player.position.y + delta.y, player.position.x + delta.x };
            if (world.getNode(newPos)) {
                player.position = newPos;
                auto node = world.getNode(newPos);
                std::cout << "You move to (" << newPos.y << ", " << newPos.x << ") - "
                    << node->name << " (" << terrainTypeToString(node->terrain) << ")\n";
            }
            else {
                std::cout << "You can’t go that way — unexplored terrain.\n";
            }
            currentTerrain = world.getTerrainAt(player.position);
            break;
        }
        case '5': {
            int minY = -20, maxY = 20;
            int minX = -20, maxX = 20;
            world.displayMapArea(-20, 20, -20, 20, player.position);
            break;
        }
        case '6':
            running = false;
            break;
        default:
            std::cout << "Invalid option.\n";
        }
    }
}

void showAvailableActions(const WorldMap& world, const Coordinate& playerPos) {
    TerrainType terrain = world.getTerrainAt(playerPos);

    std::cout << "\nAvailable actions:\n";
    std::cout << "1. Move\n";

    if (canTalkToPeople(terrain)) {
        std::cout << "2. Talk to locals\n";
    }

    if (canSearchLibrary(terrain)) {
        std::cout << "3. Search the library\n";
    }

    std::cout << "0. Exit\n";
}