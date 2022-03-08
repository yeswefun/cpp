#include <iostream>

using namespace std;

class Printer {
private:
    Printer() {
        m_count = 0;
    }
    Printer(const Printer &p) {
    }
private:
    static Printer* mInstance;
    int m_count;
public:
    static Printer* getInstance() {
        return mInstance;
    }
    void print(string task) {
        cout << ++m_count << '-' << task << endl;
    }
};

Printer* Printer::mInstance = new Printer;

int main() {
    Printer *p1 = Printer::getInstance();
    Printer *p2 = Printer::getInstance();
    Printer *p3 = Printer::getInstance();
    cout << (p1 == p2) << endl;
    cout << (p3 == p2) << endl;
    p1->print("line1");
    p1->print("line2");
    p1->print("line3");
    p1->print("line4");
    return 0;
}
