#include "WorldMap.h"
#include "Player.h"
#include <iostream>

void movePlayer(Player& player) {
    char input;
    std::cout << "Move (N/S/E/W): ";
    std::cin >> input;

    if (input == 'N' || input == 'n') player.position.y += 1;
    else if (input == 'S' || input == 's') player.position.y -= 1;
    else if (input == 'E' || input == 'e') player.position.x += 1;
    else if (input == 'W' || input == 'w') player.position.x -= 1;

    std::cout << "Moved to (" << player.position.y << ", " << player.position.x << ")\n";
}