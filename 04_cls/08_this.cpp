#include <iostream>

using namespace std;

class Dog {
public:
    void show() {
        cout << "show" << endl;
    }
    void showId() {
        if (this == NULL) {
            cout << "this == NULL" << endl;
            return;
        }
        // NULL->id -> segmentation fault
        cout << "show: " << id << endl;
    }
    int id;
};

/*
    this指针指向NULL
        不操作对象成员属性是没有问题的
*/
int main() {
    Dog *p = NULL;
    p->show();  // ok
    p->showId();// err
    return 0;
}
