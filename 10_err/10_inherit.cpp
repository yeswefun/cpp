#include <iostream>
#include <stdexcept>

using namespace std;

class MyOutOfRangeException : public exception {
public:

    MyOutOfRangeException(string msg) {
        this->msg = msg;
    }

    virtual ~MyOutOfRangeException() {

    }

    virtual const char* what() const noexcept {
        /*
            string -> char*, myString.c_str()
            char* -> string, string(myCharStr)
        */
        return this->msg.c_str();
    }

private:
    string msg;
};

void test() {
    throw MyOutOfRangeException(string("error: MyOutOfRangeException"));
}

/*
    异常 + 多态
*/
int main() {

    try {
        test();
    } catch (exception &e) {
        cout << "exceptioin: " << e.what() << endl;
    } catch (...) {
        cout << "main: other error" << endl;
    }

    return 0;
}
