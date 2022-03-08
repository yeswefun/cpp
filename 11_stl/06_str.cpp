#include <iostream>
#include <string>

using namespace std;

/*
    string和c-style字符串转换
*/
int main() {

    //string 转 char*
    string str = "hello";
    const char* cstr = str.c_str();
    cout << cstr << endl;

    //char* 转 string
    // warning: ISO C++ forbids converting a string constant to ‘char*’ 
    // char* s = "hell"; // warning
    // char* s = (char*)"hell"; // ok
    char s[] = "world";
    string str2(s);
    cout << str2 << endl;
    
    return 0;
}
