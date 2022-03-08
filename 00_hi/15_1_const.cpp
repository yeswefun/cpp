#include <iostream>

using namespace std;

struct User {
    //User() {}
    int id;
    string name;
};

/*
    const修饰自定义数据类型会分配内存
*/
int main() {
    //const User u;//此时必须提供默认构造
    const User u = {6, "Java"};
    cout << u.id << "#" << u.name << endl;
    //u.id = 66;
    //u.name = "jerry";
    User *p = (User*) &u;
    p->id = 8;
    p->name = "Cpp";
    cout << u.id << "#" << u.name << endl;
    return 0;
}
