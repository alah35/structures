#ifndef MECHANICS_H
#define MECHANICS_H
#include "control.h"
#include "../headers/characters.h"

void fill_field();
void show_field();
void place_enemies();
void place_player();
void update_field();
bool is_game_over(char &w);
bool is_there_character(int y, int x);
void do_attack(Character &ch, int y, int x);
void action(Control command, Character &ch);
void save_game(int &round);
void load_game(int &round);

#endif
