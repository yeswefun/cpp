#include <iostream>
#include <map>

using namespace std;

void fnPrint(map<int, int> m) {
    for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
        cout << it->first << '@' << it->second << endl;
    }
}

int main() {

    map<int, int> m;
    m.insert(make_pair(1, 11));
    m.insert(make_pair(2, 22));
    m.insert(make_pair(3, 33));
    m.insert(make_pair(4, 44));
    fnPrint(m);
    cout << "*********************************" << endl;

    m.erase(3);
    fnPrint(m);
    cout << "*********************************" << endl;

    map<int, int>::iterator pos = m.find(2);
    if (pos == m.end()) {
        cout << "not found" << endl;
    } else {
        cout << pos->first << '@' << pos->second << endl;
    }
    cout << "*********************************" << endl;

    // map: 0 / 1, 因为map的key不可以重复
    cout << m.count(0) << endl;
    cout << m.count(4) << endl;

    return 0;
}
