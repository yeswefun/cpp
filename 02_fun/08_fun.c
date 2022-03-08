#include <stdio.h>

struct User {
    int id;
    char name[16];
};

void show(const struct User *s) {
    printf("user: id: %d, name: %s\n", s->id, s->name);
}

struct Dog {
    int id;
    char name[16];
};

void show2(const struct Dog *s) {
    printf("dog: id: %d, name: %s\n", s->id, s->name);
}

// c语言将行为与属性分开
int main() {
    struct User u = {18, "Jerry"};
    show(&u);
    
    struct Dog d = {36, "Tom"};
    show2(&d);
    
    // 高能调用
    show2((struct Dog*)&u);
    return 0;
}
