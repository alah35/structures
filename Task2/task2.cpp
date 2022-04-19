#include <iostream>
#include <string>
#include <vector>
#include "structs.h"

int main() {
    Village vl;
    Land ln;
    ln.area = 10;
    vl.sites.push_back(ln);
    std::cout << vl.sites[0].area << std::endl;
    return 0;
}
