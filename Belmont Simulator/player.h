#pragma once
#include "GameData.h"

void showStats(const Player& player);
void increaseStat(Player& player, const std::string& stat, int amount);
void movePlayer(Player& player);