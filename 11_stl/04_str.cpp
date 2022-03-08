#include <iostream>
#include <string>

using namespace std;

int main() {
    string s = "hello";
    for (int x = 0; x < s.size(); ++x) {
        cout << s[x] << "@" << s.at(x) << endl;
        // the difference between [] and at()
        // out of range: [] - '\1'(win: crash), at() - exception
    }

    cout << '[' << s[100] << ']' << endl;
    cout << '[' << ((int)s[100]) << ']' << endl;
    cout << '[' << (s[100] == '\1') << ']' << endl;
    try {
        //cout << '[' << s[100] << ']' << endl; // '\1'
        cout << '[' << s.at(100) << ']' << endl;
    } catch (out_of_range &e) {
        cout << e.what() << endl;
    }

    return 0;
}
