#include <string>
#include "characters.cpp"

enum Control {
    ERR = -2,
    QUIT,
    W,
    A,
    S,
    D,
    LOAD,
    SAVE,
};

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


