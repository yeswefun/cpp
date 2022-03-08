#include <iostream>
#include <list>

using namespace std;

// 自定义类型
class A {
public:
    A(int id, int score, string name) : id(id), score(score), name(name) {}
    bool operator==(const A &a) {
        return this->id == a.id 
            && this->score == a.score 
            && this->name == a.name;
    }
    int id;
    int score;
    string name;
};

void fnPrint(list<A> L) {
    for (list<A>::iterator it = L.begin(); it != L.end(); ++it) {
        cout << it->id << '@' << it->score << '$' << it->name << endl;
    }
    cout << "*********************************" << endl;
}

bool cmp(A &x, A &y) {
    if (x.score == y.score) {
        return x.id < y.id;
    }
    return x.score > y.score;
}

int main() {
    list<A> L;
    A a(4, 30 ,"Python");
    L.push_back(a);
    L.push_back(A(8, 60 ,"Java"));
    L.push_back(A(0, 70 , "Go"));
    L.push_back(A(3, 50 ,"C++"));
    L.push_back(A(6, 60 ,"C"));
    fnPrint(L);
    
    L.sort(cmp);
    fnPrint(L);
    
    L.remove(a);
    fnPrint(L);
    
    return 0;
}
