
#include <iostream>
using namespace std;

// Non-recursive Fibonacci
void nonRecursive(int n) {
    int a = 0, b = 1, c;

    for (int i = 0; i <= n; i++) {
        cout << a << " ";
        c = a + b;
        a = b;
        b = c;
    }
}

// Recursive Fibonacci
int recursive(int n) {
    if (n <= 1)
        return n;

    return recursive(n - 1) + recursive(n - 2);
}

int main() {
    int n;

    cout << "Enter number of term: ";
    cin >> n;

    if (n < 0) {
        cout << "Please enter a non-negative number.\n";
        return 0;
    }

    cout << "\nNon-recursive Fibonacci: ";
    nonRecursive(n);

    cout << "\nRecursive Fibonacci: ";
    for (int i = 0; i <= n; i++) {
        cout << recursive(i) << " ";
    }

    if (n > 0) {
        cout << "\n\n" << n
             << "th Fibonacci number: "
             << recursive(n) << "\n";
    }

    cout << "\nTime and Space Complexity:\n";
    cout << "Non-recursive Time Complexity: O(n)\n";
    cout << "Non-recursive Space Complexity: O(1)\n";
    cout << "Recursive Time Complexity: O(2^n)\n";
    cout << "Recursive Space Complexity: O(n)\n";

    return 0;
}








































































// Theory: Fibonacci Series Using Recursive and Non-Recursive Methods
// The Fibonacci series is a sequence of numbers in which each number is obtained by adding the previous two numbers. The series starts with 0 and 1.

// Example: 0, 1, 1, 2, 3, 5, 8, 13, 21, ...

// Formula:
// \[
// F(n)=F(n-1)+F(n-2)
// \]

// Where \(F(0)=0\) and \(F(1)=1\).

// 1. Non-Recursive Method:
// - It uses a loop to generate the Fibonacci series.
// - Two variables store the previous two numbers.
// - The next number is calculated by adding these two numbers.
// - It has \(O(n)\) time complexity and \(O(1)\) space complexity.
// 2. Recursive Method:
// - It uses a function that calls itself to calculate Fibonacci numbers.
// - The base cases are \(F(0)=0\) and \(F(1)=1\).
// - The function returns the sum of the previous two Fibonacci numbers.
// - It has \(O(2^n)\) time complexity and \(O(n)\) space complexity.