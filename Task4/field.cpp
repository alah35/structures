#include <iostream> 
#include <characters.cpp>

void fill_field(char (&f)[40][40]) {
    for (int i = 0; i < 40; i++) {
        for (int j = 0; j < 40; j++) {
            f[i][j] = '.';
        }
    }
}

void show_field(const char f[][40]) {
   for (int i = 0; i < 40; i++) {
       for (int j = 0; j < 40; j++) {
           std::cout << f[i][j] << " ";
       }
       std::cout << std::endl;
   }
}

void place_character(char (&f)[40][40], Character (&enms)[5]) {
    for (int i = 0; i < 5; i++) {

        do {
            Location loc(rand() % 41, rand() %41);
            enms[i].locate = loc;
        } while (f[enms[i].locate.y][enms[i].locate.x] != '.');

        f[enms[i].locate.y][enms[i].locate.x] = 'E';
    }
}

void place_character(char (&f)[40][40], Character &plr) {
    
    do {
        Location loc(rand() % 40, rand() % 40);
        plr.locate = loc;
    } while (f[plr.locate.y][plr.locate.x] != '.');

    f[plr.locate.y][plr.locate.x] = 'P';
}


