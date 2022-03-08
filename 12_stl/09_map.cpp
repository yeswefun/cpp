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
    m.insert(pair<int, int>(1, 11));
    m.insert(make_pair(2, 12));
    m.insert(map<int, int>::value_type(3, 13));
    m[4] = 14;
    fnPrint(m);
    cout << "*********************************" << endl;

    //m[5];
    cout << m[5] << endl;
    cout << "*********************************" << endl;

    // 添加了一个索引为5的元素值为该类型默认值
    fnPrint(m);
    
    return 0;
}
