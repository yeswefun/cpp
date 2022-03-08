#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void fnPrint(int x) {
    cout << x << endl;
}

/*
    反向遍历
*/
int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    for (vector<int>::reverse_iterator it = v.rbegin();
        it != v.rend(); ++it) {
        cout << *it << endl;
    }

    cout << "*********************************" << endl;

    for_each(v.rbegin(), v.rend(), fnPrint);

    return 0;
}
