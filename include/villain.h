#ifndef VILLAIN_H
#define VILLAIN_H

#include "trainer.h"

typedef enum {
    VILLAIN_RANK_GRUNT,
    VILLAIN_RANK_ADMIN,
    VILLAIN_RANK_EXECUTIVE,
    VILLAIN_RANK_LEADER
} VillainRank;

typedef struct {
    char name[25];
    TrainerType type;
    VillainRank rank;
    Pokemon *pokemon[6];
    int pokemon_count;
    int level;
    u8 defeated;
} VillainTrainer;

typedef struct {
    char name[30];
    char leader_name[25];
    char description[100];
    VillainTrainer *members[20];
    int member_count;
} VillainOrganization;

VillainOrganization* villain_org_create(const char *name, const char *leader);
void villain_org_add_member(VillainOrganization *org, VillainTrainer *member);

#endif
