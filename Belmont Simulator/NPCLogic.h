#pragma once
#include "GameData.h"

bool canConvinceNPC(Player& player, NPC& npc);
void gatherSpecificKnowledge(Player& player, VampireKnowledge& vampire, NPC& npc);
void gatherGeneralKnowledge(Player& player, NPC& npc);
NPC findNPC(const std::string& location);