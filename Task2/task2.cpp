#include <iostream>
#include <string>
#include <vector>
#include "structs.h"

std::string get_build_type(BuildType type) {
    switch (type) {
case HOUSE:
        return "House";
        break;
case GARAGE:
        return "Garage";
        break;
case BARN:
        return "Barn";
        break;
case BATH:
        return "Bath";
        break;
default:
        return "Err";
        break;
    }
}

BuildType get_build_type(std::string s) {
    if (s == "House" || s == "house")
        return HOUSE;
    if (s == "Garage" || s == "garage")
        return GARAGE;
    if (s == "Barn" || s == "barn")
        return BARN;
    if (s == "Bath" || s == "bath")
        return BATH;
    return ABL;
}

std::string get_room_type(RoomType type) {
    switch (type) {
        case KITCHEN:
            return "kitchen";
            break;
        case BEDROOM:
            return "bedroom";
            break;
        case CHILDROOM:
            return "childroom";
            break;
        case LIVINGROOM:
            return "livingroom";
            break;
        default:
            return "Err";
            break;
    }
}

RoomType get_room_type(std::string s) {
    if (s == "Kitchen" || s == "kitchen")
        return KITCHEN;
    if (s == "Bedroom" || s == "vedroom")
        return BEDROOM;
    if (s == "Childroom" || s == "childroom")
        return CHILDROOM;
    if (s == "Livingroom" || s == "livingroom")
        return LIVINGROOM;
    return NON_ROOM;
}

void set_properties(Building &build) {
    switch (build.type) {
        case HOUSE:
            {
                std::cout << "Enter the area of the house:" << std::endl;
                std::cin >> build.area;
                std::cout << "Is there a fireplace in the house?\n[y/n]:";
                char ans;
                std::cin >> ans;
                build.isThereFireplace(ans == 'y');
                std::cout << "How many floors are there in the house?" << std::endl;
                int af;
                std::cin >> af;
                build.setAmountFloors(af);
                for (int f = 0; f < build.getAmountFloors(); f++) {
                    Floor currentFloor;
                    std::cout << "The " <<  f + 1 << " floor:" << std::endl;
                    std::cout << "Which is the floor height?" << std::endl;
                    std::cin >> currentFloor.height;
                    std::cout << "How many rooms are there on the floor?" << std::endl;
                    int ar;
                    std::cin >> ar;
                    currentFloor.setAmountRooms(ar);
                    for (int r = 0; r < currentFloor.getAmountRooms(); r++) {
                        Room currentRoom;
                        std::cout << "What is the type of the " << r + 1;
                        std::cout << " room? (kitchen, bedroom, bathroom, childroom, livingroom):" << std::endl;
                        std::string roomType;
                        std::cin >> roomType;
                        currentRoom.type = get_room_type(roomType);
                        std::cout << "Whis is the area of the room?" << std::endl;
                        std::cin >> currentRoom.area;
                        currentFloor.rooms.push_back(currentRoom);
                    }
                    build.floors.push_back(currentFloor);
                }
            }
            break;

        case GARAGE:
            {
                std::cout << "Which is the area of the Garage:" << std::endl;
                std::cin >> build.area;
            } 
            break;

        case BARN:
            {
                std::cout << "Which is the area of the BARN:" << std::endl;
                std::cin >> build.area;
            }
            break;

            case BATH:
            {
                std::cout << "Which is the area of the Bath:" << std::endl;
                std::cin >> build.area;
                std::cout << "Is there a fireplace in the Bath:\n[y/n]:" << std::endl;
                char ans;
                std::cin >> ans;
                build.isThereFireplace(ans == 'y');
            }
    }

}

double get_buildings_area(Village *vl) {
    int buildingsArea = 0;
    for (int i = 0; i < vl->sites.size(); i ++) {
        buildingsArea += vl->sites[i].get_buildings_area();
    }
    return buildingsArea;
}


int main() {
    Village vl;
    std::cout << "Enter how many sites in the village?" << std::endl;
    std::cin >> vl.amountSites;
    for (int i = 0; i < vl.amountSites; i++) {
        Land currentSite;
        std::cout << "The "  << i + 1 << " site:" << std::endl;
        std::cout << "Which is the area of this site?" << std::endl;
        std::cin >> currentSite.area;
        std::cout << "How many buildings in this site?" << std::endl;
        std::cin >> currentSite.amountOfBuildings;

        for (int j = 0; j < currentSite.amountOfBuildings; j++) {
            Building currentBuilding;
            std::cout << "The "  << j + 1 << " building:" << std::endl;
            std::cout << "Enter a type of the building (House, Garage, Barn, Bath):" << std::endl;
            std::string buildType;
            std::cin >> buildType;
            currentBuilding.type = get_build_type(buildType);
            set_properties(currentBuilding);
            currentSite.buildings.push_back(currentBuilding);
        }

        vl.sites.push_back(currentSite);
    }

    std::cout << get_buildings_area(&vl) << std::endl;
    std::cout << vl.get_village_area() << std::endl;

    return 0;
}
