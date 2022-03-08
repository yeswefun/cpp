#include <iostream>
#include <vector>

using namespace std;

/*
    重新分配了多少次内存空间
*/
int main() {
    vector<int> v;
    // 预留18个元素的空间
    // v.reserve(18); // 取消注释
    int num = 0;
    int *p = NULL;
    for (int x = 0; x < 18; ++x) {
        v.push_back(x);
        // 重新分配了多少次内存空间
        if (p != &v[0]) {
            p = &v[0];
            ++num;
        }
    }
    cout << num << endl;
    return 0;
}
