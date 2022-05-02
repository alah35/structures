#include "../headers/control.h"
    
Control interpret(std::string s) {
    if (s == "quit" || s == "q")
        return QUIT;
    if (s == "w" || s == "W")
        return W;
    if (s == "a" || s == "A")
        return A;
    if (s == "s" || s == "S")
        return S;
    if (s == "d" || s == "D")
        return D;
    if (s == "Load" || s == "load")
        return LOAD;
    if (s == "Save" || s == "save")
        return SAVE;
    return ERR;
}


