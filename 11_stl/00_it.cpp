#include <iostream>
#include <vector>	 // vector
#include <algorithm> // for_each

using namespace std;

void fnPrint(int v) {
    cout << v << endl;
}

/*
    基本类型

    三种遍历方式

    迭代器类似指针
        v.begin() 第一个元素, 
        v.end() 最后一个元素的下一位元素
*/
int main() {
    // 声明容器
    vector<int> v;  // 10, 20, 30
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    // 方式1
    vector<int>::iterator begin = v.begin();
    vector<int>::iterator end = v.end();
    while (begin != end) {
        cout << *begin << endl;
        ++begin;
    }
    cout << "************************" << endl;

    // 方式2
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        cout << *it << endl;
    }
    cout << "************************" << endl;

    // 方式3
    for_each(v.begin(), v.end(), fnPrint);
    
    return 0;
}
