#include <iostream>
#include <queue>

using namespace std;

/*
    FIFO
    遍历所有元素
*/
int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << "front: " << q.front() << endl;
    cout << "back: " << q.back() << endl;
    while (!q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }
    return 0;
}
