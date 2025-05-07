#include <iostream>
#include "GameData.h"
#include "player.h"

void showStats(const Player& player) {
    std::cout << "\n-- Player Stats --\n";
    std::cout << "Name: " << player.name << "\n";
    std::cout << "Prowess: " << player.prowess << "\n";
    std::cout << "Wit: " << player.wit << "\n";
    std::cout << "Presence: " << player.presence << "\n";
    std::cout << "Repute: " << player.repute << "\n";
    std::cout << "Mettle: " << player.mettle << "\n";
}

void increaseStat(Player& player, const std::string& stat, int amount) {
    if (stat == "prowess") player.prowess += amount;
    else if (stat == "wit") player.wit += amount;
    else if (stat == "presence") player.presence += amount;
    else if (stat == "repute") player.repute += amount;
}