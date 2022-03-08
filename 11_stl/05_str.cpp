#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "hello world";
    int pos1 = s.find("l");
    int pos2 = s.find("l", 3);
    int pos3 = s.find("l", 4);
    int pos4 = s.find("l", 10);
    cout << pos1 << endl;   // 2
    cout << pos2 << endl;   // 3
    cout << pos3 << endl;   // 9
    cout << pos4 << endl;   // -1
    cout << "*********************************" << endl;

    string x = "hello world";
    int pos5 = x.rfind("o");
    int pos6 = x.rfind("e");
    cout << pos5 << endl;   // -> 7
    cout << pos6 << endl;   // -> 1

    return 0;
}
