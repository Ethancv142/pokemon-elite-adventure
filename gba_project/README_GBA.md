# Magic Valley GBA Prototype

This folder contains a small Game Boy Advance prototype of "Magic Valley" (وادي الأرواح الساحر) intended to run on a GBA emulator such as My Boy. It's a minimal demo showing:
- simple console UI
- wild encounter that can make a Pokemon follow the player
- a waterfall location that can trigger evolution for specific species

Important: This is a small proof-of-concept built for libgba/devkitPro. You'll need to install devkitPro/devkitARM to build the .gba file.

Files in this folder:
- Makefile: Build rules (requires devkitPro)
- source/main.c: Main C source (uses libgba console functions)
- README_GBA.md: Build and run instructions

Notes & limitations:
- Placeholder text-based demo (no sprites or graphics beyond the built-in text console)
- Uses simple in-memory structures; no persistent save across sessions
- Intended as a starting point. You (or I) can expand it with tilemaps/sprites and saving.
