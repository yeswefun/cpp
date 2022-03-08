#include <iostream>

using namespace std;

class Test {
public:
    Test() {
        cout << "construct" << endl;
    }
    ~Test() {
        cout << "destruct" << endl;
    }
};

int main() {
    Test t; // stack，自动分配内存，自动释放内存
    Test *t2 = new Test(); // heap，手动分配内存，手动释放内存
    delete t2;
    return 0;
}
