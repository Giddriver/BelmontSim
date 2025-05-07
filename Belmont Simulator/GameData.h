#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> // For rand()
#include "Coordinate.h"

struct Player {  
   std::string name;  
   int prowess = 5;  
   int wit = 5;  
   int presence = 5;  
   int repute = 0;  
   int mettle = 5;  
   Coordinate position;  

   Player(const std::string& playerName, int playerProwess, int playerWit,  
          int playerPresence, int playerRepute, int playerMettle,  
          Coordinate start)  
       : name(playerName), prowess(playerProwess), wit(playerWit),  
         presence(playerPresence), repute(playerRepute), mettle(playerMettle), position(start) {  
   }  
   Player() = default;  
};

struct VampireKnowledge {
    std::string name;
    std::string location;
    std::string preferredPrey;
    int age;
    std::vector<std::string> traits;  // Example: "can turn into a bat"
    std::vector<std::string> thrallIdentities;  // Names of thralls
    std::vector<std::string> relationships;  // Allies or enemies
};

struct GeneralKnowledge {
    std::vector<std::string> weaknesses;  // Garlic, sunlight, etc.
    std::vector<std::string> strengths;   // Immortality, speed, etc.
    std::vector<std::string> abilities;   // Hypnotism, shape-shifting, etc.
    std::vector<std::string> lore;        // Historical accounts, myths
    std::vector<std::string> culture;     // Vampire society or rituals
};

struct NPC {
    std::string name;
    std::string role; // Hermit, witch, villager, etc.
    std::string location;
    std::string gender;
    bool isFriendly; // Whether they will teach you
    GeneralKnowledge generalKnowledge;
    VampireKnowledge specificKnowledge;
};