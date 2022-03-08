#include <iostream>
using namespace std;

#include "03_game1.h"
#include "03_game2.h"

/*
    命名空间可以防止命名冲突

    $ g++ 03_space.cpp 03_game1.cpp 03_game2.cpp -o 03.out
*/
int main() {
    G1::attack();
    G2::attack();
    return 0;
}
