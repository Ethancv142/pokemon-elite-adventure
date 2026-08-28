#ifndef MAIN_H
#define MAIN_H

#include <gba.h>

typedef enum {
    STATE_TITLE,
    STATE_OVERWORLD,
    STATE_BATTLE,
    STATE_MENU,
    STATE_DIALOG,
    STATE_POKEMON_CENTER,
    STATE_POKE_MART,
    STATE_GYM_BATTLE,
    STATE_ELITE_FOUR,
    STATE_CHAMPION_BATTLE
} GameState;

typedef struct {
    GameState state;
    GameState prev_state;
    int frame_counter;
} GameContext;

void game_init();
void game_update();
void game_render();
void game_change_state(GameState new_state);

#endif
