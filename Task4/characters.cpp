#include <string>
#include <iostream>

struct Location {

    Location() {
        y = 0;
        x = 0;
    }

    Location(int a, int b) {
        y = a;
        x = b;
    }

    bool operator==(const Location& right ) {
        return y == right.y && x == right.x;
    }

    int y;
    int x;
};

struct Character {
    std::string name;
    int health = 50;
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
        return health <= 0;
    }

    void attack(Character &target) {
        target.armor -= damage;
        if (target.armor < 0) {
            target.health += target.armor;
            target.armor = 0;
        }
    }

    void show_stats() {
        std::cout << "--Stats--" << std::endl;
        std::cout << "Health: " << health << std::endl;
        std::cout << "Armor: " << armor << std::endl;
        std::cout << "Damage: " << damage << std::endl;
    }
};
