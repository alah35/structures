#include "mechanics.cpp"

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

        std::string direction;
        std::cout << "Make a move (use WASD):" << std::endl;
        std::cin >> direction;
        action(interpret(direction), player);
        update_field();
        std::cout << std::endl;
        show_field();
        std::cout << std::endl;
        
        for (int i = 0; i < 5; i++) {
            if (!enemies[i].have_died())
            action(static_cast<Control>(rand() % 4), enemies[i]);
        }

        update_field();
        show_field();
        player.show_stats();
        roundCounter++;
    }


    return 0;
}
