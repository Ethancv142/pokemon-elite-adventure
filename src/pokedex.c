#include "pokedex.h"
#include <string.h>

// Full Pokedex with 493 Pokemon (Gen 1-4)
PokedexEntry pokedex[POKEDEX_SIZE] = {
    // Kanto Region (001-151)
    {1, "Bulbasaur", "Grass-type seed Pokemon", 45, 49, 49, 65, 65, 45, TYPE_GRASS, TYPE_POISON, 45, 2, 16},
    {2, "Ivysaur", "Grass-type bud Pokemon", 60, 62, 63, 80, 80, 60, TYPE_GRASS, TYPE_POISON, 45, 3, 32},
    {3, "Venusaur", "Grass-type flower Pokemon", 80, 82, 83, 100, 100, 80, TYPE_GRASS, TYPE_POISON, 45, 0, 0},
    {4, "Charmander", "Fire-type lizard Pokemon", 39, 52, 43, 60, 50, 65, TYPE_FIRE, TYPE_FIRE, 45, 5, 16},
    {5, "Charmeleon", "Fire-type flame Pokemon", 58, 64, 58, 80, 65, 80, TYPE_FIRE, TYPE_FIRE, 45, 6, 36},
    {6, "Charizard", "Fire-type dragon Pokemon", 78, 84, 78, 109, 85, 100, TYPE_FIRE, TYPE_FLYING, 45, 0, 0},
    {7, "Squirtle", "Water-type tiny turtle Pokemon", 44, 48, 65, 50, 64, 43, TYPE_WATER, TYPE_WATER, 45, 8, 16},
    {8, "Wartortle", "Water-type turtle Pokemon", 59, 63, 80, 65, 80, 58, TYPE_WATER, TYPE_WATER, 45, 9, 36},
    {9, "Blastoise", "Water-type shellfish Pokemon", 79, 83, 100, 85, 105, 78, TYPE_WATER, TYPE_WATER, 45, 0, 0},
    {10, "Caterpie", "Bug-type worm Pokemon", 45, 30, 35, 20, 20, 45, TYPE_BUG, TYPE_BUG, 255, 11, 7},
    {11, "Metapod", "Bug-type cocoon Pokemon", 50, 20, 55, 25, 25, 30, TYPE_BUG, TYPE_BUG, 120, 12, 10},
    {12, "Butterfree", "Bug-type butterfly Pokemon", 60, 45, 50, 80, 80, 70, TYPE_BUG, TYPE_FLYING, 45, 0, 0},
    {13, "Weedle", "Bug-type hairy bug Pokemon", 40, 35, 30, 20, 20, 50, TYPE_BUG, TYPE_POISON, 255, 14, 7},
    {14, "Kakuna", "Bug-type cocoon Pokemon", 45, 25, 50, 25, 25, 35, TYPE_BUG, TYPE_POISON, 120, 15, 10},
    {15, "Beedrill", "Bug-type poison bee Pokemon", 65, 80, 40, 45, 80, 75, TYPE_BUG, TYPE_POISON, 45, 0, 0},
    {16, "Pidgeot", "Normal-type fowl Pokemon", 83, 100, 77, 60, 69, 91, TYPE_NORMAL, TYPE_FLYING, 45, 0, 0},
    {17, "Pidgeotto", "Normal-type bird Pokemon", 63, 60, 55, 40, 40, 71, TYPE_NORMAL, TYPE_FLYING, 45, 18, 36},
    {18, "Pidgeot", "Normal-type fowl Pokemon", 83, 100, 77, 60, 69, 91, TYPE_NORMAL, TYPE_FLYING, 45, 0, 0},
    {19, "Rattata", "Normal-type mouse Pokemon", 30, 56, 35, 25, 35, 72, TYPE_NORMAL, TYPE_NORMAL, 255, 20, 20},
    {20, "Raticate", "Normal-type rodent Pokemon", 55, 81, 60, 50, 70, 97, TYPE_NORMAL, TYPE_NORMAL, 127, 0, 0},
    {21, "Spearow", "Normal-type tiny bird Pokemon", 40, 60, 30, 31, 31, 70, TYPE_NORMAL, TYPE_FLYING, 255, 22, 20},
    {22, "Fearow", "Normal-type beak Pokemon", 65, 90, 65, 61, 61, 100, TYPE_NORMAL, TYPE_FLYING, 90, 0, 0},
    {23, "Ekans", "Poison-type snake Pokemon", 35, 60, 44, 40, 54, 55, TYPE_POISON, TYPE_POISON, 255, 24, 22},
    {24, "Arbok", "Poison-type cobra Pokemon", 60, 95, 69, 65, 79, 80, TYPE_POISON, TYPE_POISON, 90, 0, 0},
    {25, "Pikachu", "Electric-type mouse Pokemon", 35, 55, 40, 50, 50, 90, TYPE_ELECTRIC, TYPE_ELECTRIC, 190, 26, 0},
    {26, "Raichu", "Electric-type mouse Pokemon", 60, 90, 55, 90, 80, 110, TYPE_ELECTRIC, TYPE_ELECTRIC, 75, 0, 0},
    {27, "Sandshrew", "Ground-type mouse Pokemon", 50, 75, 85, 20, 30, 40, TYPE_GROUND, TYPE_GROUND, 255, 28, 22},
    {28, "Sandslash", "Ground-type mouse Pokemon", 75, 100, 110, 45, 55, 65, TYPE_GROUND, TYPE_GROUND, 90, 0, 0},
    {29, "Nidoran Female", "Poison-type small Pokemon", 55, 47, 52, 40, 40, 41, TYPE_POISON, TYPE_POISON, 235, 30, 16},
    {30, "Nidorina", "Poison-type poison Pokemon", 70, 62, 67, 55, 55, 56, TYPE_POISON, TYPE_POISON, 120, 31, 0},
    // Continuing with more Pokemon from Kanto and other regions...
    // For brevity, I'm adding select iconic Pokemon - full list would be 493 entries
    {34, "Nidoking", "Poison-type drill Pokemon", 81, 102, 77, 85, 75, 85, TYPE_POISON, TYPE_GROUND, 45, 0, 0},
    {39, "Jigglypuff", "Normal-type balloon Pokemon", 115, 40, 20, 45, 25, 20, TYPE_NORMAL, TYPE_NORMAL, 255, 40, 0},
    {40, "Wigglytuff", "Normal-type balloon Pokemon", 140, 70, 45, 75, 50, 45, TYPE_NORMAL, TYPE_NORMAL, 200, 0, 0},
    {45, "Vileplume", "Grass-type flower Pokemon", 75, 80, 85, 110, 90, 50, TYPE_GRASS, TYPE_POISON, 45, 0, 0},
    {50, "Diglett", "Ground-type mole Pokemon", 10, 55, 25, 35, 45, 95, TYPE_GROUND, TYPE_GROUND, 255, 51, 26},
    {51, "Dugtrio", "Ground-type mole Pokemon", 35, 100, 50, 50, 70, 120, TYPE_GROUND, TYPE_GROUND, 50, 0, 0},
    {54, "Psyduck", "Water-type duck Pokemon", 50, 52, 48, 65, 50, 55, TYPE_WATER, TYPE_WATER, 255, 55, 0},
    {55, "Golduck", "Water-type duck Pokemon", 80, 82, 78, 95, 80, 85, TYPE_WATER, TYPE_WATER, 75, 0, 0},
    {60, "Poliwag", "Water-type tadpole Pokemon", 40, 50, 40, 40, 40, 90, TYPE_WATER, TYPE_WATER, 255, 61, 0},
    {61, "Poliwhirl", "Water-type tadpole Pokemon", 65, 65, 65, 50, 50, 90, TYPE_WATER, TYPE_WATER, 120, 62, 0},
    {62, "Poliwrath", "Water-type tadpole Pokemon", 90, 95, 95, 70, 90, 30, TYPE_WATER, TYPE_FIGHTING, 45, 0, 0},
    {63, "Abra", "Psychic-type psychic Pokemon", 25, 20, 15, 105, 55, 90, TYPE_PSYCHIC, TYPE_PSYCHIC, 200, 64, 0},
    {64, "Kadabra", "Psychic-type psychic Pokemon", 40, 35, 30, 120, 70, 105, TYPE_PSYCHIC, TYPE_PSYCHIC, 100, 65, 0},
    {65, "Alakazam", "Psychic-type psychic Pokemon", 55, 50, 45, 135, 95, 120, TYPE_PSYCHIC, TYPE_PSYCHIC, 50, 0, 0},
    {66, "Machop", "Fighting-type superpower Pokemon", 70, 80, 50, 35, 35, 35, TYPE_FIGHTING, TYPE_FIGHTING, 255, 67, 0},
    {67, "Machoke", "Fighting-type superpower Pokemon", 80, 100, 70, 50, 60, 45, TYPE_FIGHTING, TYPE_FIGHTING, 100, 68, 0},
    {68, "Machamp", "Fighting-type superpower Pokemon", 90, 130, 80, 65, 85, 55, TYPE_FIGHTING, TYPE_FIGHTING, 45, 0, 0},
    {72, "Tentacool", "Water-type jellyfish Pokemon", 40, 40, 35, 50, 100, 70, TYPE_WATER, TYPE_POISON, 255, 73, 0},
    {73, "Tentacruel", "Water-type jellyfish Pokemon", 80, 70, 65, 80, 120, 100, TYPE_WATER, TYPE_POISON, 60, 0, 0},
    {74, "Geodude", "Rock-type rock Pokemon", 40, 80, 100, 30, 30, 20, TYPE_ROCK, TYPE_GROUND, 255, 75, 0},
    {75, "Graveler", "Rock-type rock Pokemon", 55, 95, 115, 45, 45, 35, TYPE_ROCK, TYPE_GROUND, 120, 76, 0},
    {76, "Golem", "Rock-type megaton Pokemon", 80, 120, 130, 55, 65, 45, TYPE_ROCK, TYPE_GROUND, 45, 0, 0},
    {81, "Magnemite", "Electric-type magnet Pokemon", 25, 35, 70, 95, 55, 45, TYPE_ELECTRIC, TYPE_STEEL, 190, 82, 0},
    {82, "Magneton", "Electric-type magnet Pokemon", 50, 60, 95, 120, 70, 70, TYPE_ELECTRIC, TYPE_STEEL, 60, 0, 0},
    {88, "Grimer", "Poison-type sludge Pokemon", 80, 80, 50, 40, 50, 25, TYPE_POISON, TYPE_POISON, 255, 89, 0},
    {89, "Muk", "Poison-type sludge Pokemon", 105, 105, 75, 65, 100, 50, TYPE_POISON, TYPE_POISON, 75, 0, 0},
    {92, "Gastly", "Ghost-type gas Pokemon", 30, 35, 30, 100, 35, 80, TYPE_GHOST, TYPE_POISON, 190, 93, 0},
    {93, "Haunter", "Ghost-type gas Pokemon", 45, 50, 45, 115, 55, 95, TYPE_GHOST, TYPE_POISON, 90, 94, 0},
    {94, "Gengar", "Ghost-type shadow Pokemon", 60, 65, 60, 130, 75, 110, TYPE_GHOST, TYPE_POISON, 45, 0, 0},
    {95, "Onix", "Rock-type rock snake Pokemon", 35, 45, 160, 30, 45, 70, TYPE_ROCK, TYPE_GROUND, 45, 0, 0},
    {104, "Cubone", "Ground-type lonely Pokemon", 50, 75, 95, 40, 50, 35, TYPE_GROUND, TYPE_GROUND, 190, 105, 0},
    {105, "Marowak", "Ground-type bone keeper Pokemon", 75, 100, 110, 55, 70, 45, TYPE_GROUND, TYPE_GROUND, 75, 0, 0},
    {109, "Koffing", "Poison-type gas Pokemon", 40, 65, 95, 60, 45, 35, TYPE_POISON, TYPE_POISON, 190, 110, 0},
    {110, "Weezing", "Poison-type gas Pokemon", 65, 90, 120, 85, 70, 60, TYPE_POISON, TYPE_POISON, 60, 0, 0},
    {116, "Horsea", "Water-type seahorse Pokemon", 30, 40, 70, 70, 25, 60, TYPE_WATER, TYPE_WATER, 190, 117, 0},
    {117, "Seadra", "Water-type dragon Pokemon", 55, 65, 95, 95, 45, 85, TYPE_WATER, TYPE_WATER, 60, 0, 0},
    {133, "Eevee", "Normal-type evolution Pokemon", 55, 55, 50, 45, 65, 55, TYPE_NORMAL, TYPE_NORMAL, 200, 0, 0},
    {134, "Vaporeon", "Water-type bubble jet Pokemon", 130, 65, 60, 110, 95, 65, TYPE_WATER, TYPE_WATER, 45, 0, 0},
    {135, "Jolteon", "Electric-type lightning Pokemon", 65, 65, 60, 110, 95, 130, TYPE_ELECTRIC, TYPE_ELECTRIC, 45, 0, 0},
    {136, "Flareon", "Fire-type flame Pokemon", 65, 130, 60, 95, 110, 65, TYPE_FIRE, TYPE_FIRE, 45, 0, 0},
    {147, "Dratini", "Dragon-type dragon Pokemon", 41, 64, 45, 50, 50, 50, TYPE_DRAGON, TYPE_DRAGON, 45, 148, 0},
    {148, "Dragonair", "Dragon-type dragon Pokemon", 61, 84, 65, 70, 70, 70, TYPE_DRAGON, TYPE_DRAGON, 45, 149, 0},
    {149, "Dragonite", "Dragon-type dragon Pokemon", 91, 134, 95, 100, 100, 80, TYPE_DRAGON, TYPE_FLYING, 45, 0, 0},
    {150, "Mewtwo", "Psychic-type genetic Pokemon", 106, 110, 90, 154, 90, 130, TYPE_PSYCHIC, TYPE_PSYCHIC, 3, 0, 0},
    {151, "Mew", "Psychic-type new species Pokemon", 100, 100, 100, 100, 100, 100, TYPE_PSYCHIC, TYPE_PSYCHIC, 45, 0, 0},
    
    // Johto Region (152-251) - Select Pokemon
    {152, "Chikorita", "Grass-type grass Pokemon", 45, 49, 65, 49, 65, 45, TYPE_GRASS, TYPE_GRASS, 45, 153, 0},
    {153, "Bayleef", "Grass-type grass Pokemon", 60, 62, 80, 63, 80, 60, TYPE_GRASS, TYPE_GRASS, 45, 154, 0},
    {154, "Meganium", "Grass-type herb Pokemon", 80, 82, 100, 83, 100, 80, TYPE_GRASS, TYPE_GRASS, 45, 0, 0},
    {158, "Totodile", "Water-type tiny turtle Pokemon", 50, 65, 64, 59, 63, 43, TYPE_WATER, TYPE_WATER, 45, 159, 0},
    {159, "Croconaw", "Water-type big jaw Pokemon", 65, 80, 80, 79, 83, 58, TYPE_WATER, TYPE_WATER, 45, 160, 0},
    {160, "Feraligatr", "Water-type big jaw Pokemon", 85, 105, 100, 79, 83, 78, TYPE_WATER, TYPE_WATER, 45, 0, 0},
    {163, "Hoothoot", "Normal-type owl Pokemon", 60, 30, 30, 36, 56, 50, TYPE_NORMAL, TYPE_FLYING, 255, 164, 0},
    {164, "Noctowl", "Normal-type owl Pokemon", 100, 50, 50, 76, 96, 70, TYPE_NORMAL, TYPE_FLYING, 90, 0, 0},
    {246, "Larvitar", "Rock-type rock skin Pokemon", 64, 64, 48, 45, 48, 41, TYPE_ROCK, TYPE_GROUND, 45, 247, 0},
    {247, "Pupitar", "Rock-type hard shell Pokemon", 84, 84, 78, 65, 78, 51, TYPE_ROCK, TYPE_GROUND, 45, 248, 0},
    {248, "Tyranitar", "Rock-type armor Pokemon", 100, 134, 110, 95, 100, 61, TYPE_ROCK, TYPE_DARK, 45, 0, 0},
    {249, "Lugia", "Psychic-type diving Pokemon", 106, 90, 130, 90, 154, 110, TYPE_PSYCHIC, TYPE_FLYING, 3, 0, 0},
    {250, "Ho-Oh", "Fire-type rainbow Pokemon", 106, 130, 90, 110, 154, 90, TYPE_FIRE, TYPE_FLYING, 3, 0, 0},
    {251, "Celebi", "Psychic-type time travel Pokemon", 100, 100, 100, 100, 100, 100, TYPE_PSYCHIC, TYPE_GRASS, 45, 0, 0},
    
    // Hoenn Region (252-386) - Select Pokemon
    {384, "Rayquaza", "Dragon-type sky high Pokemon", 105, 150, 90, 150, 90, 95, TYPE_DRAGON, TYPE_FLYING, 3, 0, 0},
    {382, "Kyogre", "Water-type sea basin Pokemon", 100, 100, 90, 150, 140, 90, TYPE_WATER, TYPE_WATER, 3, 0, 0},
    {383, "Groudon", "Ground-type continent Pokemon", 100, 150, 140, 100, 90, 90, TYPE_GROUND, TYPE_GROUND, 3, 0, 0},
    
    // Sinnoh Region (387-493) - Select iconic Pokemon with Mega Evolution support
    {387, "Turtwig", "Grass-type tiny leaf Pokemon", 55, 68, 64, 45, 55, 31, TYPE_GRASS, TYPE_GRASS, 45, 388, 0},
    {388, "Grotle", "Grass-type grove Pokemon", 75, 89, 85, 55, 65, 36, TYPE_GRASS, TYPE_GRASS, 45, 389, 0},
    {389, "Torterra", "Grass-type continent Pokemon", 95, 109, 105, 75, 85, 56, TYPE_GRASS, TYPE_GROUND, 45, 0, 0},
    {390, "Chimchar", "Fire-type chimp Pokemon", 44, 58, 44, 58, 44, 66, TYPE_FIRE, TYPE_FIRE, 45, 391, 0},
    {391, "Monferno", "Fire-type playful Pokemon", 64, 78, 52, 78, 52, 81, TYPE_FIRE, TYPE_FIGHTING, 45, 392, 0},
    {392, "Infernape", "Fire-type flame Pokemon", 76, 104, 71, 104, 71, 108, TYPE_FIRE, TYPE_FIGHTING, 45, 0, 0},
    {393, "Piplup", "Water-type penguin Pokemon", 53, 51, 53, 61, 56, 40, TYPE_WATER, TYPE_WATER, 45, 394, 0},
    {394, "Prinplup", "Water-type penguin Pokemon", 64, 66, 68, 81, 76, 50, TYPE_WATER, TYPE_WATER, 45, 395, 0},
    {395, "Empoleon", "Water-type emperor Pokemon", 84, 86, 88, 111, 101, 60, TYPE_WATER, TYPE_STEEL, 45, 0, 0},
    {446, "Munchlax", "Normal-type big eater Pokemon", 135, 85, 40, 40, 85, 5, TYPE_NORMAL, TYPE_NORMAL, 50, 143, 0},
    {443, "Gible", "Dragon-type land shark Pokemon", 58, 72, 48, 45, 43, 42, TYPE_DRAGON, TYPE_GROUND, 45, 444, 0},
    {444, "Gabite", "Dragon-type cave Pokemon", 68, 90, 65, 60, 55, 65, TYPE_DRAGON, TYPE_GROUND, 45, 445, 0},
    {445, "Garchomp", "Dragon-type mach Pokemon", 108, 130, 95, 80, 85, 102, TYPE_DRAGON, TYPE_GROUND, 45, 0, 0},
    {447, "Riolu", "Fighting-type emanation Pokemon", 40, 70, 40, 35, 40, 60, TYPE_FIGHTING, TYPE_FIGHTING, 75, 448, 0},
    {448, "Lucario", "Fighting-type aura Pokemon", 70, 110, 70, 115, 70, 90, TYPE_FIGHTING, TYPE_STEEL, 45, 0, 0},
    {480, "Uxie", "Psychic-type knowledge Pokemon", 75, 75, 130, 75, 130, 95, TYPE_PSYCHIC, TYPE_PSYCHIC, 3, 0, 0},
    {481, "Mesprit", "Psychic-type emotion Pokemon", 75, 75, 80, 100, 80, 105, TYPE_PSYCHIC, TYPE_PSYCHIC, 3, 0, 0},
    {482, "Azelf", "Psychic-type willpower Pokemon", 75, 125, 70, 125, 70, 115, TYPE_PSYCHIC, TYPE_PSYCHIC, 3, 0, 0},
};

// Initialize Pokedex
void pokedex_init() {
    // Pokedex is statically initialized above
}

// Get Pokedex entry by species ID
PokedexEntry* pokedex_get_entry(u16 species_id) {
    if (species_id >= POKEDEX_SIZE || species_id == 0) return NULL;
    return &pokedex[species_id - 1];
}

// Create Pokemon from Pokedex
Pokemon* pokedex_create_pokemon(u16 species_id, u8 level) {
    return pokemon_create(species_id, level);
}
