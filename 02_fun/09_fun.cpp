#include <iostream>

using namespace std;

struct User {
    int id;
    char name[16];
    void show() {
        cout << "user: " << id << '-' << name << endl;
    }
};

struct Dog {
    int id;
    char name[16];
    void show() {
        cout << "dog: " << id << '-' << name << endl;
    }
};

/*
    cpp将行为与属性封装为一个整体
    struct的默认访问权限是public
    class的默认访问权限是private

    将方法公开，将属性隐藏
    类成员包括属性与方法
    public, protected, private
*/
int main() {
    User s = {18, "Jerry"};
    s.show();
    Dog d = {36, "Tom"};
    d.show();
    return 0;
}