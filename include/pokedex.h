#ifndef POKEDEX_H
#define POKEDEX_H

#include "pokemon.h"

#define POKEDEX_SIZE 493

typedef struct {
    u16 dex_id;
    char name[25];
    char description[100];
    u8 base_hp, base_attack, base_defense;
    u8 base_sp_attack, base_sp_defense, base_speed;
    PokemonType type1, type2;
    u8 catch_rate;
    u8 evolution_id;
    u8 evolution_level;
} PokedexEntry;

extern PokedexEntry pokedex[POKEDEX_SIZE];

void pokedex_init();
PokedexEntry* pokedex_get_entry(u16 species_id);
Pokemon* pokedex_create_pokemon(u16 species_id, u8 level);

#endif
