#include <iostream>
#include <cmath>  // Include cmath for the pow function
#include <string>

using namespace std;

// Function to calculate the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to calculate the Karatsuba product of two integers
long long karatsuba(long long x, long long y) {
    // Base case for recursion
    if (x < 10 || y < 10) {
        return x * y;
    }

    // Calculate the size of the numbers
    int m = max(to_string(x).length(), to_string(y).length());
    int half = m / 2;

    // Split the digits at the middle
    long long high1 = x / pow(10, half);
    long long low1 = x % (long long)pow(10, half);
    long long high2 = y / pow(10, half);
    long long low2 = y % (long long)pow(10, half);

    // Recursive calls to calculate three products
    long long z0 = karatsuba(low1, low2);
    long long z1 = karatsuba((low1 + high1), (low2 + high2));
    long long z2 = karatsuba(high1, high2);

    // Use the three products to get the final result
    return (z2 * pow(10, 2 * half)) + ((z1 - z2 - z0) * pow(10, half)) + z0;
}

int main() {
    long long num1, num2;

    cout << "Enter two positive integers:" << endl;
    cin >> num1 >> num2;

    // Check for negative input
    if (num1 < 0 || num2 < 0) {
        cout << "Error: Only positive integers are allowed." << endl;
        return -1;
    }

    // Call the Karatsuba multiplication function
    long long result = karatsuba(num1, num2);

    cout << "The product is: " << result << endl;

    return 0;
}
