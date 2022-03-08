#include <iostream>

using namespace std;

class Calc {
public:
    Calc(int v1, int v2) : v1(v1), v2(v2) {}
    int getResult(char o) {
        if (o == '+') {
            return this->v1 + this->v2;
        } else if (o == '-') {
            return this->v1 - this->v2;
        }
        return -1;
    }
private:
    int v1;
    int v2;
};

/*
    计算器-问题引出

    开闭原则：对扩展开放，对修改关闭
*/
int main() {
    Calc calc(100, 10);
    cout << calc.getResult('+') << endl;
    cout << calc.getResult('-') << endl;
    return 0;
}
