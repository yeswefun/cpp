#include <iostream>
#include <cstdlib>

using namespace std;

struct User {
    int id;
};

/*
    二级指针
*/
void test00(User **p) {
    // **p - User
    //  *p - User*
    //   p - User**
    *p = (User*) malloc(sizeof(User));
    (*p)->id = 666;
}
/*
    指针引用
*/
void test01(User* &p) {
    p = (User*) malloc(sizeof(User));
    p->id = 888;
}

/*    
*/
int main() {
    
    // 二级指针
    User *p = NULL;
    test00(&p);
    cout << p->id << endl;
    free(p);

    // 指针引用
    User *p2 = NULL;
    test01(p2);
    cout << p2->id << endl;
    free(p2);

    return 0;
}
