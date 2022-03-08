#include <iostream>
#include <vector>

using namespace std;

/*
    巧用swap收缩空间
*/
int main() {
    vector<int> v;
    for (int x = 0; x < 100; ++x) {
        v.push_back(x);
    }
    cout << "size: " << v.size() << endl;
    cout << "capacity: " << v.capacity() << endl;

    v.resize(3);
    cout << "size: " << v.size() << endl;
    cout << "capacity: " << v.capacity() << endl;

    // vector<int>(v)：利用v作为匿名对象的初始化参数
    // 此时编译器是按照v的size来分配匿名对象的空间,
    // 匿名对象的size == capacity == v.size
    vector<int>(v).swap(v);
    cout << "size: " << v.size() << endl;
    cout << "capacity: " << v.capacity() << endl;    
    return 0;
}
