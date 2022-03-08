#include <iostream>
#include <set>

using namespace std;

/*
    set 不可以插入相同的值

    multiset允许插入重复值
*/
int main() {

    set<int> s;

    pair<set<int>::iterator, bool> flag = s.insert(1);
    if (flag.second) {
        cout << "ok" << endl;
    } else {
        cout << "err" << endl;
    }

    flag = s.insert(1);
    if (flag.second) {
        cout << "ok" << endl;
    } else {
        cout << "err" << endl;
    }

    cout << "size: " << s.size() << endl; // 1

    // multiset允许插入重复值
    multiset<int> mul;
    mul.insert(1);
    mul.insert(1);
    cout << mul.size() << endl; // 2
    
    return 0;
}
