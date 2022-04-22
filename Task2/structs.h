enum RoomType {
    NON_ROOM = -1,
    KITCHEN,
    BEDROOM, 
    BATHROOM, 
    CHILDROOM,
    LIVINGROOM
};

enum BuildType {
    ABL = -1,
    HOUSE,
    GARAGE,
    BARN,
    BATH
};

struct Room {

    RoomType type;
    double area = 5;
};

struct Floor {

    void setAmountRooms(int a) {
        if (a >= 2 && a <= 4)
            amountRooms = a;
    }

    int getAmountRooms() {
        return amountRooms;
    }

    double height = 3;
    std::vector<Room> rooms;
    private:
    int amountRooms = 2;
};

struct Building {

    void isThereFireplace(bool a) {
        if (type == HOUSE || type == BATH)
            fireplace = a;
    }

    bool isThereFireplace() {
        return fireplace;
    }

    void setAmountFloors(int a) {
        if (a >= 1 && a <= 3) 
            amountfloors = a;
    }

    int getAmountFloors() {
        return amountfloors;
    }

    bool isCorrectArea() {
        double roomsArea = 0;
        for (int a = 0; a < floors.size(); a++) {
            for (int b = 0; b < floors[a].rooms.size(); b++) {
                roomsArea += floors[a].rooms[b].area;
            }
        }
        if (roomsArea / floors.size() > area) {
            std::cout << "Summary area of the rooms is greater than house's area!" << std::endl;
            return false;
        }
        return true;
    }

    BuildType type;
    double area;
    std::vector<Floor> floors;
    private:
    int amountfloors = 1;
    bool fireplace;
};

struct Land {
    double get_buildings_area() {
        double buildingsArea = 0;
        for (int k = 0; k < buildings.size(); k++) {
            buildingsArea += buildings[k].area;
        }
        if (buildingsArea > area) {
            std::cout << "Summary area of the buildings is greater than the site's area!" << std::endl;
            return -1;
        }
        return buildingsArea;
    }

    double area = 0;
    int amountOfBuildings = 1;
    std::vector<Building> buildings;
};

struct Village {
    double get_village_area() {
        double totalArea = 0;
       for (int i = 0; i < sites.size(); i++) {
           totalArea += sites[i].area;
       }
       return totalArea;
    }
    int amountSites = 0;
    std::vector<Land> sites;
};

