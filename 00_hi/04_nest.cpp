#include <iostream>

using namespace std;

int a = 100;

namespace A {

    int a = 200;
    int b = 100;

    namespace B {
        int a = 300;
        int b = 200;
    }
}

/*
    命名空间可以嵌套命名空间
*/
int main() {
    int a = 400;
    cout << a << endl;			// 400
	cout << ::a << endl;		// 100
    cout << A::a << endl;		// 200
    cout << A::B::a << endl;	// 300
    cout << A::b << endl;		// 100
    cout << A::B::b << endl;	// 200
    return 0;
}
