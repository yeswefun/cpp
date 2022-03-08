#include <iostream>

using namespace std;

int a = 100;

int main() {
    int a = 200;
    cout << a << endl;		// 200
    cout << ::a << endl;	// 100，:: for global scope
    return 0;
}
