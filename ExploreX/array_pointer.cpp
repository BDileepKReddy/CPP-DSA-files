#include <iostream>
using namespace std;

void byValue(int x) {
    x = 100;
}

void byReference(int &x) {
    x = 100;
}

int main() {
    int arr[5] = {10, 20, 30, 40, 50};

    cout << "Array elements: ";
    for(int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }

    int x = 10;
    int* ptr = &x;

    cout << "Value of x: " << x << endl;
    cout << "Address of x: " << &x << endl;
    cout << "Pointer ptr stores: " << ptr << endl;
    cout << "Value at pointer: " << *ptr << endl;

    int array[3] = {1, 2, 3};
    int* p = array; // same as &arr[0]

    cout << *(p + 0) << " ";
    cout << *(p + 1) << " ";
    cout << *(p + 2) << endl;

    int a = 5;
    int &ref = a;

    ref = 10; // modifies 'a'

    cout << "a = " << a << endl;    // 10
    cout << "ref = " << ref << endl; // 10

    int num = 10;

    byValue(num);
    cout << "After pass-by-value: " << num << endl;

    byReference(num);
    cout << "After pass-by-reference: " << num << endl;

    int v[2][3] = { {1, 2, 3}, {4, 5, 6} };

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}
