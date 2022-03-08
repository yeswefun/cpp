#include <iostream>

using namespace std;

/*
    template<class T> 等价于 template<typename T>
 */ 
template<typename T>
void xswap(T &x, T &y) {
    T tmp = x;
    x = y;
    y = tmp;
}

/*
    类型参数化 - 泛型编程 - 模板技术

    error: call of overloaded ‘swap(int&, int&)’ is ambiguous
    c++的标准库中也有个std::swap函数
*/
int main() {

    int x = 10, y = 20;
    cout << x << " @ " << y << endl;
    // xswap(x, y);        // 隐式推导
    xswap<int>(x, y);      // 显式指定类型
    cout << x << " @ " << y << endl;

    double a = 2.71828, b = 3.1415926;
    cout << a << " @ " << b << endl;
    // xswap(a, b);        // 隐式推导
    xswap<double>(a, b);   // 显式指定类型
    cout << a << " @ " << b << endl;
    
    // 自动类型推导，必须是编译器能找到匹配的调用类型
    // error: no matching function for call to ‘xswap(int, char)’
    // xswap(10, 'c');

    return 0;
}
