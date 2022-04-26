#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "field.cpp"

bool is_game_over(Character *plr, Character enms[], char &w) {

    if (plr->have_died()) {
        w = 'P';
        return true;
    }

    int enemyAlive = 0;
    for (int i = 0; i < 5; i++) {
        enemyAlive += !enms[i].have_died();
    }
    
    if (enemyAlive == 0) {
        w = 'P';
        return true;
    }
    
    return false;
}

int main() {
    char field[40][40];
    fill_field(field);

    Character player;
    player.create_player();

    Character enemies[5];
    for (int i = 0; i < 5; i++) {
        enemies[i].create_enemy();
        enemies[i].name += std::to_string(i);
    }

    place_character(field, enemies);
    place_character(field, player);
    
    char  winner;
    int roundCounter = 1;
    while (!is_game_over(&player, enemies, winner)) {
        std::cout << "----------ROUND " << roundCounter << "----------" << std::endl;
        show_field(field);
        std::string direction;
        std::cout << "make a move (use WASD):" << std::endl;
        std::cin >> direction;
    }


    return 0;
}
