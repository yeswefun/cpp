#include <iostream>
#include "09_arr.h"

using namespace std;

void test00() {
    Arr arr;
    Arr arr2(18);
}

void test01() {
    Arr arr3;
    for (int x = 0; x < 6; x++) {
        arr3.push(x + 10);
    }
    for (int x = 0; x < 6; x++) {
        cout << arr3.get(x) << endl;
    }
}

void test02() {
    // 声明一个指针变量, 并赋值为pArr，指向同一块内存
    //Arr *pArr = new Arr(18);
    //Arr *arr3 = pArr;
    //delete pArr;
    Arr *arr3 = new Arr();
    for (int x = 0; x < 6; x++) {
        arr3->push(x + 10);
    }
    for (int x = 0; x < 6; x++) {
        cout << arr3->get(x) << endl;
    }
    delete arr3;
}

void test03() {
    Arr arr;
    arr.push(1);
    arr.push(2);
    arr.push(3);
    cout << arr.get(0) << "@" << arr.get(1) << "@" << arr.get(2) << endl;
    arr.set(0, 3);
    arr.set(1, 2);
    arr.set(2, 1);
    cout << arr.get(0) << "@" << arr.get(1) << "@" << arr.get(2) << endl;
}

// arr[0]
// arr[0] = 6;
void test04() {
    Arr arr;
    cout << "len: " << arr.getLen() << endl;
    cout << "cap: " << arr.getCap() << endl;
    arr.push(1);
    arr.push(2);
    arr.push(3);
    cout << "len: " << arr.getLen() << endl;
    cout << "cap: " << arr.getCap() << endl;

    cout << arr[0] << endl;
    cout << arr[1] << endl;
    cout << arr[2] << endl;
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    cout << arr[0] << endl;
    cout << arr[1] << endl;
    cout << arr[2] << endl;
}

int main() {
    
    test00();
    cout << "************************" << endl;

    test01();
    cout << "************************" << endl;

    test02();
    cout << "************************" << endl;

    test03();
    cout << "************************" << endl;

    test04();
    cout << "************************" << endl;

    return 0;
}
