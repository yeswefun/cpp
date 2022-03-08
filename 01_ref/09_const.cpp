#include <iostream>

using namespace std;

/*
    常量引用用来修饰形参
        防止函数在调用过程中修改形参的值
*/
void show(const int &val) {
    cout << val << endl;
    //val = 888; //error: assignment of read-only reference ‘val’
}

int main() {
    int a = 666;
    show(a);
    cout << a << endl;
    return 0;
}
