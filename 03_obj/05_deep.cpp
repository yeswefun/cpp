#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

class Dog {
public:
    Dog() {
        cout << "Dog" << endl;
    }
    Dog(int id, const char *name) {
        m_id = id;
        m_name = (char*) malloc(strlen(name) + 1);
        strcpy(m_name, name);
    }
    // 系统会提供拷贝构造，简单赋值
    Dog(const Dog &d) {
        m_id = d.m_id;
        m_name = (char*) malloc(strlen(d.m_name) + 1);
        strcpy(m_name, d.m_name);
        cout << "copy" << endl;
    }
	~Dog() {
        if (m_name != NULL) {
            free(m_name);
            m_name = NULL;
        }
        cout << "destruct dog: " << this << " # " << m_id << endl;
    }
    int m_id;
    char *m_name;
};

int main() {
    Dog dog(666, "Java");
    Dog dog2(dog);
    return 0;
}
