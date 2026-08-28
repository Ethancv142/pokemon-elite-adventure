/*
 * Magic Valley - minimal GBA prototype
 * - Requires devkitPro / libgba
 * - Console-based demo using consoleDemoInit() and iprintf
 * Controls:
 *  - A: Trigger a wild encounter
 *  - B: Use waterfall (try to evolve followers with location-based evolution)
 *  - START: List current followers
 *  - SELECT: Clear followers
 *
 * Build with: make (in the directory that contains the Makefile)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <gba_console.h>
#include <gba_input.h>
#include <gba_systemcalls.h>
#include <gba_interrupt.h>

#define MAX_FOLLOWERS 6

typedef struct {
    char species[24];
    int level;
    int friendship; // 0-100
    int is_follower;
} Pokemon;

static const char* wild_species[] = { "Spiritmon", "Skyfin", "Glimmora" };
static const float follow_rates[] = { 0.7f, 0.5f, 0.6f };

Pokemon followers[MAX_FOLLOWERS];
int follower_count = 0;

// Simple RNG helper
static unsigned int rand_seed = 123456;
static int myrand()
{
    rand_seed = rand_seed * 1664525 + 1013904223;
    return (rand_seed >> 16) & 0x7FFF;
}

void add_follower(const char* species, int level)
{
    if (follower_count >= MAX_FOLLOWERS) return;
    Pokemon *p = &followers[follower_count++];
    strncpy(p->species, species, sizeof(p->species)-1);
    p->species[sizeof(p->species)-1] = '\0';
    p->level = level;
    p->friendship = 50;
    p->is_follower = 1;
}

void clear_followers()
{
    int i;
    for (i=0;i<MAX_FOLLOWERS;i++) followers[i].is_follower = 0;
    follower_count = 0;
}

void list_followers()
{
    iprintf("Followers (%d):\n", follower_count);
    int i;
    for (i=0;i<follower_count;i++) {
        Pokemon *p = &followers[i];
        iprintf("%d) %s L%d FR:%d\n", i+1, p->species, p->level, p->friendship);
    }
    if (follower_count==0) iprintf("(none)\n");
}

void wild_encounter()
{
    int idx = myrand() % (sizeof(wild_species)/sizeof(wild_species[0]));
    const char* s = wild_species[idx];
    int lvl = 20 + (myrand() % 11); // level 20-30
    iprintf("You encountered a wild %s L%d\n", s, lvl);
    float r = (myrand() % 10000) / 10000.0f;
    if (r < follow_rates[idx]) {
        iprintf("It decided to follow you!\n");
        add_follower(s, lvl);
    } else {
        iprintf("It ran away...\n");
    }
}

// Simulate location-based evolution: Glimmora -> GlimmoraAstra at waterfall
void use_waterfall()
{
    iprintf("You used the Glow Waterfall. Checking followers...\n");
    int evolved = 0;
    int i;
    for (i=0;i<follower_count;i++) {
        Pokemon *p = &followers[i];
        if (strcmp(p->species, "Glimmora") == 0) {
            strncpy(p->species, "GlimmoraAstra", sizeof(p->species)-1);
            p->species[sizeof(p->species)-1] = '\0';
            p->level += 2;
            p->friendship = 100;
            evolved++;
            iprintf("%s evolved into GlimmoraAstra!\n", "Glimmora");
        }
    }
    if (!evolved) iprintf("No followers could evolve here.\n");
}

int main(void)
{
    irqInit();
    irqEnable(IRQ_VBLANK);

    consoleDemoInit();
    iprintf("Magic Valley - GBA Prototype\n");
    iprintf("A: Encounter  B: Waterfall  START: List  SELECT: Clear\n\n");

    while (1) {
        scanKeys();
        u16 keys = keysDown();

        if (keys & KEY_A) {
            wild_encounter();
        }
        if (keys & KEY_B) {
            use_waterfall();
        }
        if (keys & KEY_START) {
            list_followers();
        }
        if (keys & KEY_SELECT) {
            clear_followers();
            iprintf("Followers cleared.\n");
        }

        swiWaitForVBlank();
    }
    return 0;
}
