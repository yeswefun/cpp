#include <iostream>
#include <set>

using namespace std;

void fnPrint(set<int> s) {
    for (set<int>::iterator it = s.begin(); it != s.end(); ++it) {
        cout << *it << endl;
    }
    cout << "size: " << s.size() << endl;
    cout << "empty:" << s.empty() << endl;
    cout << "*********************************" << endl;
}

/*
    序列式容器与关联式容器

    关联式容器会对key时行排序，从小到大

    基本操作
*/
int main() {
    set<int> s;
    
    // 关联式容器会对key时行排序，从小到大
    s.insert(9);
    s.insert(3);
    s.insert(7);
    s.insert(1);
    fnPrint(s);

    s.erase(s.begin());
    fnPrint(s);

    s.erase(7);
    fnPrint(s);
    
    return 0;
}
