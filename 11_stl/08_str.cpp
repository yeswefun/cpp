#include <iostream>
#include <string>

using namespace std;

/*
    string长度超过容量时，会自动扩容，
    之前对相关字符进行引用操作的变量会全部失效
*/
int main() {

    string s = "abcDEF";
    for (int x = 0; x < s.size(); ++x) {
        //s[x] = toupper(s[x]);
        s[x] = tolower(s[x]);
    }
    cout << s << endl;

    cout << "*********************************" << endl;

    string str = "hello";
    char &a = str[2];
    char &b = str[3];
    a = 'x';
    b = 'y';
    cout << str << endl;
    cout << (int*)str.c_str() << endl;	// 0x7ffe3f6538e0

    // 为什么地址不会发生改变 - 长度没有超过其初始容量
    str = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
    a = '1';
    b = '2';
    cout << str << endl;
    cout << (int*)str.c_str() << endl;	// 0x5558b5a4d280

    return 0;
}
