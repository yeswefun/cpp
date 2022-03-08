#include <iostream>

using namespace std;

/*
    1.引用变量必须初始化
*/
void test01() {
    // error: ‘a’ declared as reference but not initialized
    // int &a;
}

/*
    2.引用变量初始化后，不能再作为其它变量的别名

    因为引用变量必须初始化，但若想作为其它变量的别名，则必须重新定义 - error
*/
int main() {

    int a = 10;
    int &b = a;
    cout << b << endl; // 10

    // 下面的意思并不是为变量c起别名为b
    int c = 20;
    b = c; // 将变量c中的值赋给变量b
    cout << b << endl; // 20

    // 引用变量初始化后，不能再作为其它变量的别名
    // int &b = c;
    return 0;
}