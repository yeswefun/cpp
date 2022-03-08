#include <iostream>

using namespace std;

/*
    智能指针: 在栈上对象中存放堆内存对象，让栈上对象自动释放堆内存对象
*/
class Item {
public:
    Item() {
        cout << "Item#construct" << endl;
    }
    Item(int id) {
        this->id = id;
        cout << "Item#construct: " << id << endl;
    }
    void showId() {
        cout << this->id << endl;
    }
    ~Item() {
        cout << "Item#destruct" << endl;
    }
private:
    int id;
};


class Demo {
public:
    Demo() {
        cout << "Demo#construct" << endl;
    }   
    Demo(Item *p) {
        cout << "Demo#construct(Demo *p)" << endl;
        this->p = p;
    }   
    //Demo->show == Demo->p->show
    //Item*& operator->() {return this->p;}
    Item* operator->() {
        return this->p;
    }
    Item& operator*() {
        return *(this->p);
    }
    ~Demo() {
        cout << "Demo#destruct: " << this->p << endl;
        if (this->p != NULL) {
            delete this->p;
            this->p = NULL;
        }
    }   
private:
    Item *p;
};

/*
    智能指针: 
        在栈上对象中存放堆内存对象，让栈上对象自动释放堆内存对象
    
    符号重载: ->, *
*/
int main() {
    Demo d = Demo(new Item(6));
    //d->->showId() == this->p->showId(); // 编译器优化了
    d->showId();
    (*d).showId();
    return 0;
}
