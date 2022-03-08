#include <iostream>
#include <set>

using namespace std;

class A {
public:
    A(int id, string name) : id(id), name(name) {}
    int id;
    string name;
};

class cmp {
public:
    bool operator()(const A &x, const A &y) {
        return x.id > y.id;
    }
};

void fnPrint(set<A, cmp> s) {
    for (set<A, cmp>::iterator it = s.begin(); it != s.end(); ++it) {
        cout << it->id << '@' << it->name << endl;
    }
}

/*
    类类型必须在定义set对象时指定排序规则
*/
int main() {
    set<A, cmp> s;
    s.insert(A(26, "Java"));
    s.insert(A(63, "C"));
    s.insert(A(75, "Python"));
    s.insert(A(68, "Go"));
    s.insert(A(99, "C++"));
    fnPrint(s);    
    return 0;
}
