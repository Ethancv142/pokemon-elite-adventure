#ifndef TRAINER_H
#define TRAINER_H

#include "pokemon.h"

#define MAX_TRAINER_POKEMON 6

typedef enum {
    TRAINER_TYPE_NORMAL,
    TRAINER_TYPE_GYM_LEADER,
    TRAINER_TYPE_ELITE_FOUR,
    TRAINER_TYPE_CHAMPION,
    TRAINER_TYPE_RIVAL,
    TRAINER_TYPE_VILLAIN
} TrainerType;

typedef struct {
    char name[25];
    TrainerType type;
    Pokemon *pokemon[MAX_TRAINER_POKEMON];
    int pokemon_count;
    int level;
    int money_reward;
    int region;
    char title[30];
    u8 can_mega_evolve;
    u8 defeated;
} Trainer;

Trainer* trainer_create(const char *name, TrainerType type, int level);
void trainer_add_pokemon(Trainer *trainer, Pokemon *poke);
void trainer_free(Trainer *trainer);

#endif
