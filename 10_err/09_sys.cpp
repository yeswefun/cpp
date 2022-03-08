#include <iostream>
#include <stdexcept>

using namespace std;

void test() {
    // throw out_of_range("exception: out_of_range");
    throw length_error("exception: length_error");
}

/*
    异常 + 多态
*/
int main() {

    try {
        test();
    } catch (out_of_range &e) {
        cout << e.what() << endl;
    } catch (exception &e) {
        cout << "exceptioin: " << e.what() << endl;
    } catch (...) {
        cout << "main: other error" << endl;
    }

    return 0;
}
