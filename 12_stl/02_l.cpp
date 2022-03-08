#include <iostream>
#include <list>

using namespace std;

void fnPrint(list<int> L) {
    for (list<int>::iterator it = L.begin(); it != L.end(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;
}

bool cmp(int x, int y) {
    return x > y;
}

int main() {

    list<int> L;
    L.push_back(1);
    L.push_back(2);
    L.push_back(3);
    L.push_back(4);
    fnPrint(L);

    // reverse
    L.reverse();
    fnPrint(L);

    // sort, 所有不支持随机访问的迭代器不可以使用系统提供的算法
    // 但是通常类的内部都会提供
    //sort(L.begin(), L.end());
    L.sort();
    fnPrint(L);

    L.sort(cmp);
    fnPrint(L);
    
    return 0;
}
