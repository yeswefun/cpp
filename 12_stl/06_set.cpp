#include <iostream>
#include <set>

using namespace std;

// sort, 因为set插入完数据后，其结构不能发生改变，
// 所以需要在插入之前，指定排序规则
class cmp {
public:
    bool operator()(int x, int y) {
        return x > y;
    }
};

void fnPrint(set<int, cmp> s) {
    for (set<int, cmp>::iterator it = s.begin(); it != s.end(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;
}

/*
    set指定排序规则
*/
int main() {
     //set<int> s;
    set<int, cmp> s;
    s.insert(66);
    s.insert(37);
    s.insert(93);
    s.insert(75);
    fnPrint(s);
    return 0;
}
