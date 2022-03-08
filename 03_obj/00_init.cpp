#include <iostream>

using namespace std;

/*
    系统默认会提供 默认构造，默认析构 的空实现
*/
class User {
public:
    /*
        名称与类名相同
        无返回值 - 不用写void
        可以重载构造函数
        定义类的对象时自动被调用
    */
    User() {
        this->x = 0;
        cout << "construct" << endl;
    }
    User(int x) {
        this->x = x; // this是指向当前对象的指针
        // this = NULL; // 不能向this赋值
        cout << "construct(int): " << x << endl;
    }
    /*
        名称为: ~类名
        无返回值 - 不用写void
        不可以重载构造函数, 必须是无参
        类的对象被销毁时自动被调用
    */
    ~User() {
        cout << "destruct: " << x << endl;
    }
private:
    int x;
};

/*
    构造函数与析构函数

    类对象内部非静态方法中隐含着指向当前对象的指针 - this

    注意观察构造与析构的顺序
*/
int main() {
    User u;
    User u2(1);
    return 0;
}
