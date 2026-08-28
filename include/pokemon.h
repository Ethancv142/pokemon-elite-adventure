#ifndef POKEMON_H
#define POKEMON_H

#include <gba.h>

#define MAX_MOVES 4
#define MAX_POKEMON_SPECIES 493

typedef enum {
    TYPE_NORMAL,
    TYPE_FIRE,
    TYPE_WATER,
    TYPE_GRASS,
    TYPE_ELECTRIC,
    TYPE_ICE,
    TYPE_FIGHTING,
    TYPE_POISON,
    TYPE_GROUND,
    TYPE_FLYING,
    TYPE_PSYCHIC,
    TYPE_BUG,
    TYPE_ROCK,
    TYPE_GHOST,
    TYPE_DRAGON,
    TYPE_DARK,
    TYPE_STEEL,
    TYPE_FAIRY
} PokemonType;

typedef struct {
    char name[25];
    u16 dex_id;
    u8 level;
    u8 hp, max_hp;
    u8 attack, defense;
    u8 sp_attack, sp_defense;
    u8 speed;
    u16 exp;
    u8 status;
    u8 moves[MAX_MOVES];
    PokemonType type1, type2;
    u8 catch_rate;
    u8 is_follower;
} Pokemon;

Pokemon* pokemon_create(u16 species_id, u8 level);
void pokemon_take_damage(Pokemon *poke, int damage);
void pokemon_heal(Pokemon *poke);
int pokemon_is_alive(Pokemon *poke);

#endif
