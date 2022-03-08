#include <iostream>
#include <cstring>

using namespace std;

/*
    将方法公开，将属性隐藏
    类成员包括属性与方法
    public, protected, private
*/
class Fruit {
public:
    void setId(int id) {
        m_id = id;
    }
    void setName(const char *name) {
        strcpy(m_name, name);
    }
    void show() {
        cout << "fruit: " << m_id << "-" << m_name << endl;
    }
private:
    int m_id = 0;
    char m_name[16];
};

int main() {
    Fruit f = Fruit();
    f.setId(6);
    f.setName("Apple");
    f.show();
    return 0;
}
