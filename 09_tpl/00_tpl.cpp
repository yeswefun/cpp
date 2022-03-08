#include <iostream>

using namespace std;

void xswap(int &x, int &y) {
    int tmp = x;
    x = y;
    y = tmp;
}

void xswap(double &x, double &y) {
    double tmp = x;
    x = y;
    y = tmp;
}

/*
    模板引出

    bool, char, short, int, long, long long,
    float, double

    类型参数化 - 泛型编程 - 模板技术
*/
int main() {
    
    int x = 10, y = 20;
    cout << x << " @ " << y << endl;
    xswap(x, y);
    cout << x << " @ " << y << endl;

    double a = 2.71828, b = 3.1415926;
    cout << a << " @ " << b << endl;
    xswap(a, b);
    cout << a << " @ " << b << endl;

    return 0;
}
