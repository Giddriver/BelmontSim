#include "Library.h"
#include <iostream>
#include <cstdlib>

void searchLibrary(Player& player) {
    std::cout << "You search through dusty bookshelves...\n";
    if (rand() % 2)
        std::cout << "You find useful vampire lore!\n";
    else
        std::cout << "You find nothing of interest.\n";
}