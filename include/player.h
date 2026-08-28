#ifndef PLAYER_H
#define PLAYER_H

#include "pokemon.h"

#define MAX_POKEMON_PARTY 6
#define MAX_POKEMON_BOX 30

typedef struct {
    char name[20];
    int x, y;
    int level;
    int money;
    int badges;
    Pokemon *party[MAX_POKEMON_PARTY];
    int party_count;
    Pokemon *pc_box[MAX_POKEMON_BOX];
    int box_count;
    Pokemon *follower_pokemon;
} Player;

void player_init(Player *player, const char *name);
void player_catch_pokemon(Player *player, Pokemon *poke);
void player_add_money(Player *player, int amount);
void player_move(Player *player, int dx, int dy);
void player_set_follower(Player *player, Pokemon *poke);

#endif
