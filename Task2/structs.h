enum RoomsType {
    kitchen,
    bedroom, 
    bathroom, 
    childroom,
    livingroom
};

struct Rooms {
    RoomsType type;
    double area = 5;
};

struct Floors {
    int amountRooms = 2;
    double height = 3;
    std::vector<Rooms> rm;
};

struct Bath {
    bool exist = false;
    double area = 0;
    bool fireplace = true;
};

struct Barn {
    bool exist = false;
    double area = 0;
};

struct Garage {
    bool exist = false;
    double area = 0;
};
struct House {
    double area = 1;
    bool fireplace = true;
    int amountFloors = 1;
    std::vector<Floors> fl;
};

struct Buildings {
    Garage gr;
    Barn br;
    Bath bt;
};

struct Land {
    double area = 0;
    int amountOfBuildings = 1;
    std::vector<Buildings> builds;
    House home;
};

struct Village {
    double area = 0;
    int amountSites = 0;
    std::vector<Land> sites;
};

