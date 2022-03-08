#include <iostream>

using namespace std;

/*
    引入布尔类型

    true(非0为真) / false(0为假)
*/
int main() {
    bool flag;
    cout << sizeof(flag) << endl;	// 1
    cout << flag << endl;		    // 0
    flag = 666;
    cout << flag << endl;			// 1
    return 0;
}



