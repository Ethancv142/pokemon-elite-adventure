#include <stdlib.h>
#include <string.h>
#include "trainer.h"
#include "pokedex.h"

// Create a new trainer
Trainer* trainer_create(const char *name, TrainerType type, int level) {
    Trainer *trainer = (Trainer *)malloc(sizeof(Trainer));
    if (!trainer) return NULL;
    
    strncpy(trainer->name, name, 24);
    trainer->name[24] = '\0';
    trainer->type = type;
    trainer->level = level;
    trainer->pokemon_count = 0;
    trainer->region = 0;
    trainer->can_mega_evolve = 0;
    trainer->defeated = 0;
    
    // Set title based on type
    switch (type) {
        case TRAINER_TYPE_GYM_LEADER:
            strcpy(trainer->title, "GYM LEADER");
            trainer->money_reward = level * 500;
            break;
        case TRAINER_TYPE_ELITE_FOUR:
            strcpy(trainer->title, "ELITE FOUR");
            trainer->money_reward = level * 750;
            break;
        case TRAINER_TYPE_CHAMPION:
            strcpy(trainer->title, "CHAMPION");
            trainer->money_reward = level * 1000;
            trainer->can_mega_evolve = 1;
            break;
        case TRAINER_TYPE_RIVAL:
            strcpy(trainer->title, "RIVAL");
            trainer->money_reward = level * 400;
            trainer->can_mega_evolve = 1;
            break;
        case TRAINER_TYPE_VILLAIN:
            strcpy(trainer->title, "VILLAIN");
            trainer->money_reward = level * 300;
            break;
        default:
            strcpy(trainer->title, "TRAINER");
            trainer->money_reward = level * 200;
    }
    
    // Initialize pokemon array
    for (int i = 0; i < MAX_TRAINER_POKEMON; i++) {
        trainer->pokemon[i] = NULL;
    }
    
    return trainer;
}

// Add Pokemon to trainer's team
void trainer_add_pokemon(Trainer *trainer, Pokemon *poke) {
    if (!trainer || !poke || trainer->pokemon_count >= MAX_TRAINER_POKEMON) {
        return;
    }
    trainer->pokemon[trainer->pokemon_count] = poke;
    trainer->pokemon_count++;
}

// Free trainer memory
void trainer_free(Trainer *trainer) {
    if (!trainer) return;
    for (int i = 0; i < trainer->pokemon_count; i++) {
        if (trainer->pokemon[i]) {
            free(trainer->pokemon[i]);
        }
    }
    free(trainer);
}
