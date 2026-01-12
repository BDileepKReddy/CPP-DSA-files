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
        int minIndex = i;

        cout << "Pass " << i+1 << " (select minimum from index " << i << " to " << n-1 << "):\n";

        for(int j = i + 1; j < n; j++) {
            cout << "  Comparing " << arr[j] << " with current minimum " << arr[minIndex] << endl;

            if(arr[j] < arr[minIndex]) {
                minIndex = j;
                cout << "  -> New minimum found: " << arr[minIndex] << " at index " << minIndex << endl;
            }
        }

        // Swap the found minimum element
        if(minIndex != i) {
            cout << "Swapping " << arr[i] << " and " << arr[minIndex] << endl;
            swap(arr[i], arr[minIndex]);
        } else {
            cout << "No swap needed in this pass.\n";
        }

        cout << "Array now: ";
        printArray(arr, n);
        cout << endl;
    }

    cout << "Sorted Array: ";
    printArray(arr, n);

    return 0;
}
