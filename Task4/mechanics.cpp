#include <iostream>
#include <string>
#include <fstream>
#include "control.cpp"

char field[40][40]; // these definition in the global space is an easier way to control
Character enemies[5]; // game process
Character player;

void fill_field() {
    for (int i = 0; i < 40; i++) {
        for (int j = 0; j < 40; j++) {
            field[i][j] = '.';
        }
    }
}

void show_field() {
    for (int i = 0; i < 40; i++) {
        for (int j = 0; j < 40; j++) {
            std::cout << field[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void place_enemies() {
    for (int i = 0; i < 5; i++) {

        do {
            Location loc(rand() % 40, rand() %40);
            enemies[i].locate = loc;
        } while (field[enemies[i].locate.y][enemies[i].locate.x] != '.');

        field[enemies[i].locate.y][enemies[i].locate.x] = 'E';
    }
}

void place_player() {

    do {
        Location loc(rand() % 40, rand() % 40);
        player.locate = loc;
    } while (field[player.locate.y][player.locate.x] != '.');

    field[player.locate.y][player.locate.x] = 'P';
}

void update_field() {
    fill_field();
    if (!player.have_died())
    field[player.locate.y][player.locate.x] = 'P';

    for (int i = 0; i < 5; i++) {
        if (!enemies[i].have_died())
            field[enemies[i].locate.y][enemies[i].locate.x] = 'E';
    }
}

bool is_game_over(char &w) {

    if (player.have_died()) {
        w = 'P';
        return true;
    }

    int enemyAlive = 0;
    for (int i = 0; i < 5; i++) {
        enemyAlive += !enemies[i].have_died();
    }
    
    if (enemyAlive == 0) {
        w = 'E';
        return true;
    }
    
    return false;
}

bool is_there_character(int y, int x) {
    if (field[y][x] != '.')
        return true;
    return false;
}

void do_attack(Character &ch, int y, int x) {
    Location placeToMove(y, x);
    if (player.locate == placeToMove && (ch.enemy ^ player.enemy)) {
        ch.attack(player);
    }
    else {
        for (int i = 0; i < 5; i++) {
            if (enemies[i].locate == placeToMove && (ch.enemy ^ enemies[i].enemy)) {
                ch.attack(enemies[i]);
                break;
            }
        }
    }
}

void action(Control command, Character &ch) { // ch - current haracter, which is moving now
    if (ch.have_died())
        return;
    switch (command) {
        case W:     
            {
                if (is_there_character(ch.locate.y - 1, ch.locate.x)) {
                    do_attack(ch, ch.locate.y - 1, ch.locate.x);
                }
                else 
                     ch.locate.y -= ch.locate.y != 0;
            }
            break;
        case A:
            {
                if (is_there_character(ch.locate.y, ch.locate.x - 1)) {
                    do_attack(ch, ch.locate.y, ch.locate.x - 1);
                }
                else
                    ch.locate.x -= ch.locate.x != 0;
            }
            break;
        case S:
            {
                if (is_there_character(ch.locate.y + 1, ch.locate.x)) {
                    do_attack(ch, ch.locate.y + 1, ch.locate.x);
                }
                else
                    ch.locate.y += ch.locate.y != 39;
            }
            break;
        case D:
            {
                if (is_there_character(ch.locate.y, ch.locate.x + 1)) {
                    do_attack(ch, ch.locate.y, ch.locate.x + 1);
                }
                else
                 ch.locate.x += ch.locate.x != 39;
            }
            break;
        case SAVE:
            break;
        case LOAD:
            break;
        case ERR:
            break;
        case QUIT:
            break;
        default:
            break;
    }
}

