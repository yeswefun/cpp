#include <iostream>

using namespace std;

int main() {

    //int &r = 10; // error, 可变变量 = 不可变变量;


    // 指向一块栈上的内存空间, const必须指向一块合法的内存地址
    //int tmp = 10;
    //const int &r = tmp;
    const int &r = 10;
    cout << r << endl;	// 10

    //r = 10; // error: assignment of read-only reference ‘r’


    int *p = (int*) &r; // no warning
    *p = 20;
    cout << r << endl;	// 20

    return 0;
}
