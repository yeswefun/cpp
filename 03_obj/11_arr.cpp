#include <iostream>

using namespace std;

class User {
public:
    User() {
        this->id = 0;
        cout << "User(): " << id << endl;
    }
    User(int id) {
        this->id = id;
        cout << "User(): " << id << endl;
    }
    ~User() {
        cout << "~User(): " << id << endl;
    }
private:
    int id;
};

int main() {

    // 在栈上可以指定构造
    User pArr2[3] = {User(1), User(2), User(3)};
    
    // new数组一定会调用无参构造函数
    // new数组时，一定要提供默认无参构造
    User *pArr = new User[3];
    delete [] pArr;
    
    return 0;
}
