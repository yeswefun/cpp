#include <iostream>
#include <vector>

using namespace std;

/*
    容量扩展方式
*/
int main() {
    vector<int> v;
    for (int x = 0; x < 10; ++x) {
        v.push_back(x);
        // 1 2 4 4 8 8 8 8 16 16
        cout << v.capacity() << ' ';
    }
    cout << endl;
    return 0;
}
