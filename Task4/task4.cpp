#include "headers/mechanics.h"
#include <string>
#include <iostream>

extern char field[40][40]; // these definitions in the global space is an easier way to control
extern Character enemies[5]; // game process
extern Character player;

int main() {
    fill_field();

    player.create_player();

    for (int i = 0; i < 5; i++) {
        enemies[i].create_enemy();
        enemies[i].name += std::to_string(i);
    }

    place_enemies();
    place_player();
    
    char winner;
    int roundCounter = 1;
    while (!is_game_over(winner)) {
        std::cout << "----------ROUND " << roundCounter << "----------" << std::endl;
        show_field();
        player.show_stats();

        std::string direction;
        std::cout << "Make a move (use WASD):" << std::endl;
        std::cin >> direction;
        if (interpret(direction) == SAVE) {
            save_game(roundCounter);
            std::cout << "Game saved" << std::endl;
            continue;
        }
        if (interpret(direction) == LOAD) {
            load_game(roundCounter);
            std::cout << "Game loaded" << std::endl;
            continue;
        }
        if (interpret(direction) == QUIT) {
            save_game(roundCounter); // autosave
            return 0;
        }
        action(interpret(direction), player);
        update_field();

        for (int i = 0; i < 5; i++) {
            if (!enemies[i].have_died())
            action(static_cast<Control>(rand() % 4), enemies[i]);
        }

        update_field();
        roundCounter++;
    }

    if (winner == 'P')
        std::cout << "You WON!" << std::endl;
    if (winner == 'E')
        std::cout << "You lose. Game Over" << std::endl;

    return 0;
}
