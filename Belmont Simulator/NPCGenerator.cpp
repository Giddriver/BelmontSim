#include "NPCGenerator.h"
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>

// Example data pools
const std::vector<std::string> npcNames = { "Elias", "Mira", "Gregor", "Thorne", "Anwen" };
const std::vector<std::string> roles = { "villager", "hermit", "wise man", "witch" };
const std::vector<std::string> locations = { "Forest", "Village", "Cave", "Town", "City"};

const std::vector<std::string> preyTypes = { "children", "nobles", "travelers", "farmers" };
const std::vector<std::string> vampireTraits = { "invisible", "charming", "beastlike", "shadowy", "telepathic" };
const std::vector<std::string> vampireRelationships = { "sire", "rival", "ally", "thrall master" };

// Random utility
int randIndex(int max) { return rand() % max; }

std::vector<std::string> readNamesFromFile(const std::string& filename) {
    std::vector<std::string> names;
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) names.push_back(line);
    }
    return names;
}

std::vector<NPC> generateAllNPCs() {
    std::vector<NPC> npcs;

    auto maleNames = readNamesFromFile("data/male_first_names.txt");
    auto femaleNames = readNamesFromFile("data/female_first_names.txt");
    auto lastNames = readNamesFromFile("data/last_names.txt");

    // Counts
    int cityCount = 40;
    int townCount = 30;
    int villageCount = 20;
    int caveCount = 5;
    int forestCount = 5;

    for (int i = 0; i < 100; ++i) {
        NPC npc;
        bool isMale = rand() % 2 == 0;

        if (isMale) {
            npc.name = maleNames[randIndex(maleNames.size())] + " " + lastNames[randIndex(lastNames.size())];
            npc.gender = "Male";
        }
        else {
            npc.name = femaleNames[randIndex(femaleNames.size())] + " " + lastNames[randIndex(lastNames.size())];
            npc.gender = "Female";
        }

        npc.generalKnowledge = {};
        npc.specificKnowledge = {};
        npc.isFriendly = rand() % 2 == 0;

        if (i < cityCount) {
            npc.location = "City";
            npc.role = "villager";
        }
        else if (i < cityCount + townCount) {
            npc.location = "Town";
            npc.role = "villager";
        }
        else if (i < cityCount + townCount + villageCount) {
            npc.location = "Village";
            npc.role = "villager";
        }
        else if (i < cityCount + townCount + villageCount + caveCount) {
            npc.location = "Cave";
            npc.role = "hermit";
        }
        else {
            npc.location = "Forest";
            npc.role = "witch";
        }

        npcs.push_back(npc);
    }

    return npcs;
}

VampireKnowledge generateRandomVampire() {
    VampireKnowledge vamp;
    vamp.name = "Vampire " + npcNames[randIndex(npcNames.size())];
    vamp.location = locations[randIndex(locations.size())];
    vamp.preferredPrey = preyTypes[randIndex(preyTypes.size())];
    vamp.age = 100 + rand() % 500;

    int traitCount = 1 + rand() % 3;
    for (int i = 0; i < traitCount; ++i) {
        vamp.traits.push_back(vampireTraits[randIndex(vampireTraits.size())]);
    }

    vamp.thrallIdentities = { "Thrall A", "Thrall B" }; // You can randomize further
    vamp.relationships.push_back(vampireRelationships[randIndex(vampireRelationships.size())]);
    return vamp;
}