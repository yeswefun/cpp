#include <iostream>
#include <cstdio>

using namespace std;

class Student {
public:
    void setId(int id) {
        m_id = id;
    }
    void setName(string name) {
        m_name = name;
    }
    string toString() {
        // return m_id + "@" + m_name; // 为什么这里会有问题
        // return m_name + "@" + m_id; // 为什么这里会有问题
        char buf[32] = {0};
        sprintf(buf, "id: %d, name: %s", m_id, m_name.c_str());
        return string(buf);
    }
public:
    int m_id;
    string m_name;
};

/*
    学生类简单封装
*/
int main() {
    // 实例化
    Student s;
    s.setId(6);
    s.setName("Jerry");
    cout << s.m_id << "@" << s.m_name << endl;
    cout << s.toString() << endl;
    return 0;
}
