#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

class Dog {
public:
    Dog() {
        cout << "construct dog" << endl;
    }
    Dog(int id, const char *name) {
        m_id = id;
        m_name = (char*) malloc(strlen(name) + 1);
        strcpy(m_name, name);
    }
    ~Dog() {
        //free(): double free detected in tcache 2
        if (m_name != NULL) {
            free(m_name);
            m_name = NULL;
        }
        cout << "destruct dog: " << m_id << endl;
    }
    // 系统会提供拷贝构造，简单赋值
    int m_id;
    char *m_name;
};

// a#m_name = 0xff00; -> free -> NULL
// b#m_name = 0xff00; -> free -> double free
int main() {
    Dog dog(666, "Java");
    Dog dog2(dog);
    return 0;
}
