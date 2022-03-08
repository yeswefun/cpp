#include <iostream>

using namespace std;

/*
    error: call of overloaded ‘swap(int&, int&)’ is ambiguous
    c++的标准库中也有个std::swap函数
*/
template<class T>
void swap_t(T &x, T &y) {
    T tmp = x;
    x = y;
    y = tmp;
}

template<class T>
void sort(T arr[], int len) {
    for (int x = 0; x < len - 1; ++x) {
        int min = x;
        for (int y = x + 1; y < len; ++y) {
            if (arr[y] < arr[min]) {
                min = y;
            }
        }
        if (min != x) {
            swap_t(arr[x], arr[min]);
        }
    }
}

template<class T>
void print(T arr[], int len) {
    for (int x = 0; x < len; ++x) {
        cout << arr[x] << ' ';
    }
    cout << endl;
}

int main() {
    int arr[] = {30, 1, 42, 28, 45, 12, 0};
    int len1 = sizeof(arr) / sizeof(arr[0]);
    print(arr, len1);
    sort(arr, len1);
    print(arr, len1);

    double arr2[] = {3.141592, 2.71828, 6.6666, 1.2345, 8.88888};
    int len2 = sizeof(arr2) / sizeof(arr2[0]);
    print(arr2, len2);
    sort(arr2, len2);
    print(arr2, len2);
    return 0;
}
