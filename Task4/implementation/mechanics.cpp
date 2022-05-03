#include <iostream>
#include <string>
#include <fstream>
#include "../headers/mechanics.h"

char field[40][40]; // these definitions in the global space is an easier way to control
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
        w = 'E';
        return true;
    }

    int enemyAlive = 0;
    for (int i = 0; i < 5; i++) {
        enemyAlive += !enemies[i].have_died();
    }
    
    if (enemyAlive == 0) {
        w = 'P';
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

void action(Control command, Character &ch) { // ch - current character, which is moving now
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
        case ERR:
            break;
        default:
            break;
    }
}

void save_game(int &round) {
    std::ofstream save("/home/alah/HomeWorks/strctrs/structures/Task4/save.bin",
                        std::ios::binary);
    int len = player.name.length();
    save.write((char*) &len, sizeof(len));
    save.write(player.name.c_str(), len);
    save.write((char*) &player.health, sizeof(player.health));
    save.write((char*) &player.armor, sizeof(player.armor));
    save.write((char*) &player.locate.y, sizeof(player.locate.y));
    save.write((char*) &player.locate.x, sizeof(player.locate.x));
    save.write((char*) &player.enemy, sizeof(player.enemy));

    for (int i = 0; i < 5; i++) {
        len = enemies[i].name.length();
        save.write((char*) &len, sizeof(len));
        save.write(enemies[i].name.c_str(), len);
        save.write((char*) &enemies[i].health, sizeof(player.health));
        save.write((char*) &enemies[i].armor, sizeof(player.armor));
        save.write((char*) &enemies[i].locate.y, sizeof(player.locate.y));
        save.write((char*) &enemies[i].locate.x, sizeof(player.locate.x));
        save.write((char*) &enemies[i].enemy, sizeof(player.enemy));
    }

    save.write((char*) &round, sizeof(round));
   
    save.write((char*) &field[0][0], sizeof(field));
}

void load_game(int &round) {
    std::ifstream load("/home/alah/HomeWorks/strctrs/structures/Task4/save.bin",
                        std::ios::binary);
    int len;
    load.read((char*) &len, sizeof(len));
    player.name.resize(len);
    load.read((char*) player.name.c_str(), len);
    load.read((char*) &player.health, sizeof(player.health));
    load.read((char*) &player.armor, sizeof(player.armor));
    load.read((char*) &player.locate.y, sizeof(player.locate.y));
    load.read((char*) &player.locate.x, sizeof(player.locate.x));
    load.read((char*) &player.enemy, sizeof(player.enemy));

    for (int i = 0; i < 5; i++) {
        load.read((char*) &len, sizeof(len));
        enemies[i].name.resize(len);
        load.read((char*) enemies[i].name.c_str(), len);
        load.read((char*) &enemies[i].health, sizeof(player.health));
        load.read((char*) &enemies[i].armor, sizeof(player.armor));
        load.read((char*) &enemies[i].locate.y, sizeof(player.locate.y));
        load.read((char*) &enemies[i].locate.x, sizeof(player.locate.x));
        load.read((char*) &enemies[i].enemy, sizeof(player.enemy));
    }

    load.read((char*) &round, sizeof(round));

    load.read((char*) &field[0][0], sizeof(field));
}
