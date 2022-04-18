#include <iostream>
#include <string>

bool isValidDate(std::string s) {
    if(s[2] != '.' || s[5] != '.') {
        std::cout << "Wrong date format";
        return false;
    }
    
    int day = std::stoi(s.substr(0,2));
    if (day <= 0 || day > 31) {
        std::cout << "Wrong day number." << std::endl;
        return false;
    }

    int month = std::stoi(s.substr(3, 2));
    if (month < 1 || month > 12) {
        std::cout << "Wrong month number." << std::endl;
        return false;
    }
    
    int year = std::stoi(s.substr(6, 4));
    if (year < 0) {
        std::cout << "Wrong year number." <<std::endl;
        return false;
    }

    return true;
}

bool isValidSalary(std::string s) {
    if (std::stoi(s) < 0) {
        std::cout << "Wrong salary number.";
        return false;
    }
    return true;
}

void changeData(std::string &s) {
    std::cout << "Enter new value:" << std::endl;
    std::cin >> s;
}


struct record {
    char* name = "name";
    char* surname = "surname";
    char* date = "DD.MM.YYYY";
    int salary = 0;
};

enum actions {
    "quit" = -1,
    "wait",
    "add",
    "list"
}

int main() {
    actions action = actions::wait;
    while (action != actions:: quit)) {
        std::cout << "What would you like to do:\nadd - to make record\nlist - to output the recrods;
        std::cin >> action;
    
}
