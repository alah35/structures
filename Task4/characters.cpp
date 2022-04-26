#include <iostream>
#include <string>

struct Location {

    Location() {
        y = 0;
        x = 0;
    }

    Location(int a, int b) {
        y = a;
        x = b;
    }

    int y;
    int x;
};

struct Character {
    std::string name;
    unsigned int health = 50;
    int armor = 0;
    int damage = 15;
    Location locate{};
    bool enemy;

    void create_player() {
        do {
            std::cout << "What is the name of your character?" << std::endl;
            std::cin >> name;
            std::cout << "Enter characteristics:" << std::endl << "Health: ";
            std::cin >> health;
            std::cout << "Armor: ";
            std::cin >> armor;
            std::cout << "Damage: ";
            std::cin >> damage;
            enemy = false; 
        } while (!is_valid_character()); 
    }

    bool is_valid_character() {
        return health > 0 && armor >= 0 && damage > 0;
    }

    void create_enemy() {
        name = "Enemy#";
        health = rand() % 101 + 50;
        armor = rand() % 51;
        damage = rand() % 16 + 15;
        enemy = true;
    }

    bool have_died() {
        return health == 0;
    }

    void show_stats() {
        std::cout << "--Stats--" << std::endl;
        std::cout << "Health: " << health << std::endl;
        std::cout << "Armor: " << armor << std::endl;
        std::cout << "Damage: " << damage << std::endl;
    }
};
