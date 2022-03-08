#include <iostream>

using namespace std;

/*
    数组引用

    对比数组指针的三种定义方式
*/
int main() {
    
    int arr[3] = {1, 2, 3};
    
    // 方式一
    int (&a)[3] = arr;

    // 方式二
    typedef int(REF)[3];
    REF &b = arr;

    // 方式三
    typedef int(&REF2)[3];
    REF2 c = arr;
    
    cout << a[0] << '-' << b[1] << '-' << c[2] << endl;

    return 0;
}
