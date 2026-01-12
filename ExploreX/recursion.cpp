#include <iostream>
using namespace std;

int fib(int n, string indent = "") {
    cout << indent << "fib(" << n << ") called" << endl;

    if(n == 0) {
        cout << indent << "Returning 0" << endl;
        return 0;
    }
    if(n == 1) {
        cout << indent << "Returning 1" << endl;
        return 1;
    }

    int result = fib(n - 1, indent + "  ") + fib(n - 2, indent + "  ");

    cout << indent << "Returning fib(" << n << ") = " << result << endl;
    return result;
}

int main() {
    int n = 6;
    cout << "Fibonacci of " << n << " using recursion:\n";
    int ans = fib(n);
    cout << "\nFinal Answer: " << ans << endl;

    // Using Tabulation Method
    int a = 0, b = 1;

    cout << "Fibonacci sequence (iterative):" << endl;
    cout << a << " " << b << " ";

    for(int i = 2; i < n; i++) {
        int c = a + b;
        cout << c << " ";

        cout << "  (Computed as " << a << " + " << b << ")" << endl;

        a = b;
        b = c;
    }
    return 0;
}
