#include <iostream>
#include <cstring>

using namespace std;

class Demo {
public:
    Demo(const char *name) {
        this->pName = new char[strlen(name)+1];
        strcpy(this->pName, name);
    }
    Demo& operator=(const Demo &o) {
        cout << "operator=" << endl;
        if (this->pName != NULL) {
            delete this->pName;
            this->pName = NULL;
        }
        this->pName = new char[strlen(o.pName) + 1];
        strcpy(this->pName, o.pName);
        return *this;
    }
    ~Demo() {
        if (this->pName != NULL) {
            cout << "delete" << endl;
            delete this->pName;
            this->pName = NULL;
        }
    }
    char *pName;
};

/*
    free(): double free detected in tcache 2
*/
int main() {
    Demo d1("test");
    Demo d2("demo");
    Demo d3("hell");
    //d2 = d1;
    d3 = d2 = d1;
    cout << d2.pName << endl;
    cout << d3.pName << endl;    
    return 0;
}

