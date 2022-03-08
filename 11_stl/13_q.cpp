#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

void fnPrint(int x) {
    cout << x << endl;
}

/*

*/
int main() {

    deque<int> q;
    q.push_back(1);
    q.push_back(2);
    q.push_back(3);
    q.push_back(4);

    // 顺序
    for (deque<int>::iterator it = q.begin(); it != q.end(); it++) {
        cout << *it << endl;
    }
    cout << "*********************************" << endl;

    // 顺序
    deque<int>::iterator begin = q.begin();
    deque<int>::iterator end = q.end();
    while (begin != end) {
        cout << *begin << endl;
        ++begin;
    }
    cout << "*********************************" << endl;

    // 顺序
    for_each(q.begin(), q.end(), fnPrint);
    cout << "*********************************" << endl;

    // 逆序
    for (deque<int>::reverse_iterator it = q.rbegin(); it != q.rend(); it++) {
        cout << *it << endl;
    }
    cout << "*********************************" << endl;

    // 逆序
    for_each(q.rbegin(), q.rend(), fnPrint);
    cout << "*********************************" << endl;

    // 顺序
    for (deque<int>::const_iterator it = q.begin(); it != q.end(); ++it) {
        cout << *it << endl;
    }
    
    return 0;
}
