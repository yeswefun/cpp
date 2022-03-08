#include <iostream>

using namespace std;

class Dog {
public:
    Dog() {
        //const Dog * const this; // 只读指针
        //this = NULL; // error，指向不能改变-指针常量
        //*this = NULL;// error，指向的变量也不能改变-常量指针
        this->a = 0;
        this->b = 0;
    }
    /*
        常函数, 不允许修改this指针指向的对象的成员
    */
    void test() const {
        //const Dog * const this;
        //error: assignment of member ‘Dog::a’ in read-only object
        //this->a = 666;
        this->b = 666;
        cout << "a: " << a << endl;
        cout << "b: " << b << endl;
    }   
    void test2() { // 普通函数
        a = 999; 
    }   
    void test3() const { // 常函数
        //a = 999;
        cout << "test3" << endl;
    }   
    int a;
	mutable int b; // mutable 无视常函数，在常函数中也可以修改
};

/*
    this是只读指针
        const Dog * const this;

    常函数与常对象

        1.常对象属性的值不允许修改

        2.常对象只可以调用常函数

    mutable 修饰对象属性，无视常函数，在常函数中也可以修改

*/
int main() {
    // 普通对象可以调用普通方法或常函数
    Dog dog;
    dog.test();

    // 常对象，不允许修改属性的值
    const Dog dog2;
    
    // 常对象属性的值不允许修改
    //error: assignment of member ‘Dog::a’ in read-only object
    //dog2.a = 888;
    
    // 常对象只可以调用常函数
    // error: passing ‘const Dog’ as ‘this’ argument discards qualifiers
    //dog2.test2();

    cout << dog2.a << endl;
    dog2.test();

    return 0;
}
