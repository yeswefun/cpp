#include <iostream>

using namespace std;

class Chairman {
private:
    // 1.私有化无参构造函数
    Chairman() {
        cout << "new" << endl;
    }
    
    // 2.私有化成员属性
    static Chairman *mInstance;
    
    // 4.私有化拷贝构造函数
    Chairman(const Chairman &c) {
        cout << "copy" << endl;
    }
public:
    // 3.公共函数返回对象
    static Chairman* getInstance() {
        return mInstance;
    }
/*一般不需要手动释放单例对象，程序运行完后系统会自动释放
    ~Chairman() {
        delete mInstance;
    }
*/
};
// 2.初始化静态成员属性，类内声明，类外初始化
Chairman *Chairman::mInstance = new Chairman;

/*
    单例设计模式
*/
int main() {
    cout << "main" << endl;
    //Chairman c1;
    //Chairman c2;
    //Chairman *c3 = new Chairman();
    Chairman *p1 = Chairman::getInstance();
    Chairman *p2 = Chairman::getInstance();
    Chairman *p3 = Chairman::getInstance();
    cout << (p1 == p2) << endl;
    cout << (p3 == p2) << endl;
    //Chairman *p4 = new Chairman(*p2);
    //cout << (p4 == p3) << endl;
    return 0;
}
