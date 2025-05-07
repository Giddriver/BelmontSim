#include "NPCLogic.h"
#include <iostream>
#include <cstdlib>

bool canConvinceNPC(Player& player, NPC& npc) {
    // If the player has high Presence, they are more likely to convince NPCs
    if (player.presence > 7) {
        std::cout << "Your charisma convinces " << npc.name << " to share their knowledge.\n";
        return true;
    }
    else {
        std::cout << npc.name << " is skeptical of your motives.\n";
        return false;
    }
}

void gatherSpecificKnowledge(Player& player, VampireKnowledge& vampire, NPC& npc) {
    std::cout << "You ask " << npc.name << " about " << vampire.name << ".\n";

    if (npc.isFriendly && canConvinceNPC(player, npc)) {
        std::cout << "They tell you about the vampire's location: " << vampire.location << "\n";
        std::cout << "They also mention that " << vampire.name << " prefers " << vampire.preferredPrey << " as prey.\n";
        // Add more details from npc.specificKnowledge...
    }
    else {
        std::cout << npc.name << " refuses to share details about " << vampire.name << ".\n";
    }
}

void gatherGeneralKnowledge(Player& player, NPC& npc) {
    std::cout << "You seek out the wise " << npc.name << " in a secluded area.\n";

    if (npc.isFriendly && canConvinceNPC(player, npc)) {
        std::cout << npc.name << " shares their vast knowledge of vampires!\n";
        // Show the general knowledge the NPC has
        for (const auto& weakness : npc.generalKnowledge.weaknesses) {
            std::cout << "Weakness: " << weakness << "\n";
        }
        // Add more general knowledge details...
    }
    else {
        std::cout << npc.name << " refuses to share their wisdom.\n";
    }
}

NPC findNPC(const std::string& location) {
    // Randomize NPCs based on location
    NPC npc;
    if (location == "Forest") {
        npc.name = "The Witch";
        npc.role = "Witch";
        npc.isFriendly = rand() % 2;  // 50% chance of being friendly
        npc.generalKnowledge.weaknesses.push_back("Sunlight");
        npc.generalKnowledge.abilities.push_back("Shape-shifting");
        // Add witch-specific knowledge...
    }
    else if (location == "Mountain") {
        npc.name = "The Hermit";
        npc.role = "Hermit";
        npc.isFriendly = rand() % 2;
        npc.generalKnowledge.weaknesses.push_back("Silver");
        npc.generalKnowledge.strengths.push_back("Immortality");
        // Add hermit-specific knowledge...
    }
    // More locations and NPCs...
    return npc;
}