#include <iostream>
using namespace std;

namespace very_long_name {
    int c = 666;
}

/*
    命名空间可以起别名
*/
int main() {
    namespace alias_name = very_long_name;
    cout << alias_name::c << endl;
    return 0;
}
