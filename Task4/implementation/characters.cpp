#include "../headers/characters.h"

Location::Location() {
    y = 0;
    x = 0;
 }

Location::Location(int a, int b) {
     y = a;
     x = b;
 }

bool Location::operator==(const Location &right) {
    return y == right.y && x == right.x;
}

void Character::create_player() {
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

bool Character::is_valid_character() {
    return health > 0 && armor >= 0 && damage > 0;
}
    
void Character::create_enemy() {
    name = "Enemy#";
    health = rand() % 101 + 50;
    armor = rand() % 51;
    damage = rand() % 16 + 15;
    enemy = true;
}

bool Character::have_died() {
    return health <= 0;
}

void Character::attack(Character &target) {
    target.armor -= damage;
    if (target.armor < 0) {
        target.health += target.armor;
        target.armor = 0;
    }
}

void Character::show_stats() {
    std::cout << "--Stats--" << std::endl;
    std::cout << name << std::endl;
    std::cout << "Health: " << health << std::endl;
    std::cout << "Armor: " << armor << std::endl;
    std::cout << "Damage: " << damage << std::endl;
}


