#ifndef REGIONS_H
#define REGIONS_H

#include "trainer.h"

#define REGION_KANTO 0
#define REGION_JOHTO 1
#define REGION_HOENN 2
#define REGION_SINNOH 3
#define REGION_UNOVA 4
#define REGION_KALOS 5
#define REGION_ALOLA 6
#define REGION_GALAR 7

typedef struct {
    char name[30];
    Trainer *gym_leaders[8];
    Trainer *elite_four[4];
    Trainer *champion;
} Region;

extern Region regions[8];

void regions_init();
Trainer* get_gym_leader(int region, int gym_index);
Trainer* get_elite_four_member(int region, int elite_index);
Trainer* get_champion(int region);

#endif
