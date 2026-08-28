#include <gba.h>
#include <stdlib.h>
#include <string.h>
#include "pokemon.h"
#include "pokedex.h"

// Create a new Pokemon instance
Pokemon* pokemon_create(u16 species_id, u8 level) {
    Pokemon *poke = (Pokemon *)malloc(sizeof(Pokemon));
    if (!poke) return NULL;
    
    PokedexEntry *dex = pokedex_get_entry(species_id);
    if (!dex) {
        free(poke);
        return NULL;
    }
    
    strncpy(poke->name, dex->name, 24);
    poke->name[24] = '\0';
    poke->dex_id = species_id;
    poke->level = level;
    poke->type1 = dex->type1;
    poke->type2 = dex->type2;
    poke->catch_rate = dex->catch_rate;
    
    // Calculate stats based on base stats and level
    poke->max_hp = ((2 * dex->base_hp + 31) * level / 100) + level + 5;
    poke->hp = poke->max_hp;
    poke->attack = ((2 * dex->base_attack + 31) * level / 100) + 5;
    poke->defense = ((2 * dex->base_defense + 31) * level / 100) + 5;
    poke->sp_attack = ((2 * dex->base_sp_attack + 31) * level / 100) + 5;
    poke->sp_defense = ((2 * dex->base_sp_defense + 31) * level / 100) + 5;
    poke->speed = ((2 * dex->base_speed + 31) * level / 100) + 5;
    
    poke->exp = 0;
    poke->status = 0; // Healthy
    poke->is_follower = 0;
    
    // Initialize moves (empty for now)
    for (int i = 0; i < MAX_MOVES; i++) {
        poke->moves[i] = 0;
    }
    
    return poke;
}

// Deal damage to Pokemon
void pokemon_take_damage(Pokemon *poke, int damage) {
    if (!poke) return;
    if (damage < 0) damage = 0;
    if (poke->hp > damage) {
        poke->hp -= damage;
    } else {
        poke->hp = 0;
    }
}

// Fully heal a Pokemon
void pokemon_heal(Pokemon *poke) {
    if (!poke) return;
    poke->hp = poke->max_hp;
    poke->status = 0;
}

// Check if Pokemon is still alive
int pokemon_is_alive(Pokemon *poke) {
    if (!poke) return 0;
    return poke->hp > 0;
}
