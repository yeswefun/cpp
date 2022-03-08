#include <iostream>
#include <stack>

using namespace std;

/*
    FILO
    遍历所有元素
*/
int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    while (s.size() != 0) {
        cout << s.top() << endl;
        s.pop();
    }
    cout << "size: " << s.size() << endl;
    return 0;
}
