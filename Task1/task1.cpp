#include <iostream>
#include <string>
#include <fstream>

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
    std::string name = "name";
    std::string surname = "surname";
    std::string date = "DD.MM.YYYY";
    std::string salary = "-1";
};

void add_record(std::string path){
    std::ofstream ofs(path, std::ios_base::app);
    while (!ofs.is_open()) {
        std::cout << "Wrong path." << std::endl;
        changeData(path);
        ofs.open(path);
    }
    record rc;
    std::cout << "Enter the name:" << std::endl;
    std::cin >> rc.name;
    std::cout << "Enter the surname:" << std::endl;
    std::cin >> rc.surname;
    std::cout << "Enter the date:" << std::endl;
    std::cin >> rc.date;
    while (!isValidDate(rc.date)) {
        changeData(rc.date);
        }
    std::cout << "Enter the salary:" << std::endl;
    std::cin >> rc.salary;
    while (!isValidSalary(rc.salary)) {
        changeData(rc.salary);
    }
    ofs << rc.name << " " << rc.surname <<  " " << rc.date << " " << rc.salary << std::endl;
    ofs.close();
    std::cout << "The record have made." << std::endl;
}

void list_table(std::string path) {
    std::ifstream ifs(path);
    std::cout << "--------------------------------------" << std::endl;
    if (!ifs.is_open())
        std::cout << "Wrong path or there is no such file." << std::endl;
    else {
        while (!ifs.eof()){
            std::string buf;
            std::getline(ifs, buf);
            std::cout << buf << std::endl;
        }
    }
     std::cout << std::endl << "--------------------------------------" << std::endl;
    ifs.close();
    
}

int main() {
    std::string path ="/home/alah/HomeWorks/strctrs/structures/Task1/table.txt";
    std::string action = "";
    while (action != "q") {
        std::cout << "What would you like to do:\nadd [a]- to make record\nlist [ls]- to output the records\n[q] - for exit" << std::endl;
        std::cin >> action;
        if (action == "add" || action == "a")
            add_record(path);
        if (action == "list" || action == "ls")
            list_table(path);
        if (action == "quit" || action == "q")
            break;
    }
    return 0;
}
