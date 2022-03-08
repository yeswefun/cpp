#include <iostream>

using namespace std;

// 引用必须引用合法内存空间
void test(int &a) {
    cout << "non-const: " << a << endl;	// 10
}

// const也可以作为重载条件
// int tmp = 10;
// const int &a = tmp;
void test(const int &a) {
    cout << "const: " << a << endl;		// 6
}

/*
    const也可以作为重载条件
*/
int main() {
    int a = 10;
    test(a);
    test(6);
    return 0;
}
