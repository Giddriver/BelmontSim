#include "WorldMap.h"
#include <iostream> // For output
#include <windows.h>

void WorldMap::displayMapArea(int minY, int maxY, int minX, int maxX, const Coordinate& playerPos) const {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int y = minY; y <= maxY; ++y) {
        for (int x = minX; x <= maxX; ++x) {
            Coordinate coord(y, x);
            const Node* node = getNode(coord);
            if (node) {
                if (coord == playerPos) {
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY); // Bright red
                    std::cout << "P "; // Player position
                }
                else {
                    switch (node->terrain) {
                    case TerrainType::Forest:
                        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                        std::cout << "F ";
                        break;
                    case TerrainType::Village:
                        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN); // Cyan
                        std::cout << "V ";
                        break;
                    case TerrainType::Cave:
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                        std::cout << "^ ";
                        break;
                    case TerrainType::City:
                        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY); // Bright blue
                        std::cout << "C ";
                        break;
                    case TerrainType::Town:
                        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED); // Yellow
                        std::cout << "T ";
                        break;
                    case TerrainType::Castle:
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE); // Magenta
                        std::cout << "K ";
                        break;
                    case TerrainType::Road:
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // White
                        std::cout << "# ";
                        break;
                    default:
                        SetConsoleTextAttribute(hConsole, 0);
                        std::cout << "? ";
                        break;
                    }
                }
            }
            else {
                SetConsoleTextAttribute(hConsole, 0);
                std::cout << ". ";
            }
        }
        std::cout << std::endl;
    }
    // Reset to default color
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}