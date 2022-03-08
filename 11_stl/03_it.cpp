#include <iostream>
#include <vector>   // vector
#include <algorithm>// for_each

using namespace std;

void fnPrint4(vector<int> v) {
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        cout << *it << endl;
    }
}

/*
    容器嵌套容器
*/
int main() {
    vector<vector<int>> v;
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;

    v1.push_back(1);
    v1.push_back(10);
    v1.push_back(100);

    v2.push_back(2);
    v2.push_back(20);

    v3.push_back(3);
    v3.push_back(30);
    v3.push_back(300);

    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);

    for_each(v.begin(), v.end(), fnPrint4);
    cout << "************************" << endl;

    for (vector<vector<int>>::iterator it1 = v.begin(); 
         it1 != v.end(); ++it1) {
        for (vector<int>::iterator it2 = (*it1).begin(); 
             it2 != (*it1).end(); ++it2) {
            cout << *it2 << endl;
        }
    }
    cout << "************************" << endl;

    vector<vector<int>>::iterator begin = v.begin();
    vector<vector<int>>::iterator end = v.end();
    while (begin != end) {
        vector<int>::iterator _begin = (*begin).begin();
        vector<int>::iterator _end = (*begin).end();
        while (_begin != _end) {
            cout << *_begin << endl;
            ++_begin;
        }
        ++begin;
    }

    return 0;
}
