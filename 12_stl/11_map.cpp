#include <iostream>
#include <map>

using namespace std;

class cmp {
public:
    bool operator()(int x, int y) {
        return x > y;
    }
};

/*
    map指定排序规则，必须在定义时指定
*/
int main() {
    map<int, int, cmp> m;
    m.insert(make_pair(1, 11));
    m.insert(make_pair(2, 22));
    m.insert(make_pair(3, 33));
    m.insert(make_pair(4, 44));
    for (map<int, int, cmp>::iterator it = m.begin(); it != m.end(); ++it) {
        cout << it->first << '@' << it->second << endl;
    }   
    return 0;
}
