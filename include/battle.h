#ifndef BATTLE_H
#define BATTLE_H

#include "pokemon.h"
#include "trainer.h"

typedef enum {
    BATTLE_STATE_START,
    BATTLE_STATE_PLAYER_TURN,
    BATTLE_STATE_ENEMY_TURN,
    BATTLE_STATE_DAMAGE,
    BATTLE_STATE_END,
    BATTLE_STATE_VICTORY,
    BATTLE_STATE_DEFEAT
} BattleState;

typedef struct {
    Pokemon *player_pokemon;
    Pokemon *enemy_pokemon;
    Trainer *enemy_trainer;
    BattleState state;
    int turn;
    int is_gym_battle;
    int is_elite_four;
} Battle;

Battle* battle_start(Pokemon *player_poke, Trainer *enemy);
void battle_update(Battle *battle);
void battle_render(Battle *battle);
void battle_player_move(Battle *battle, int move_idx);
void battle_free(Battle *battle);

#endif
