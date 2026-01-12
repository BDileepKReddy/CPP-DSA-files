#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {5, 3, 8, 4, 2};
    int n = 5;

    cout << "Initial Array: ";
    printArray(arr, n);
    cout << endl;

    for(int i = 0; i < n - 1; i++) {
        cout << "Pass " << i+1 << ":" << endl;
        bool swapped = false;

        for(int j = 0; j < n - i - 1; j++) {
            cout << "  Comparing " << arr[j] << " and " << arr[j+1];

            if(arr[j] > arr[j+1]) {
                cout << " -> Swap!";
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
            cout << endl;

            cout << "  Array now: ";
            printArray(arr, n);
        }

        if(!swapped) {
            cout << "No swaps → array is already sorted early.\n";
            break;
        }
        cout << endl;
    }

    cout << "\nSorted Array: ";
    printArray(arr, n);

    return 0;
}
