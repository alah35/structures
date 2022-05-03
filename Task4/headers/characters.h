#ifndef CHARACTERS_H
#define CHARACTERS_H
#include <string>
#include <iostream>

struct Location {

    Location();
    Location(int a, int b);

    bool operator==(const Location &right);

    int y;
    int x;
};

struct Character {
    std::string name;
    int health;
    int armor;
    int damage;
    Location locate;
    bool enemy;

    void create_player();

    bool is_valid_character();

    void create_enemy();

    bool have_died();

    void attack(Character &target);

    void show_stats();
};

#endif
