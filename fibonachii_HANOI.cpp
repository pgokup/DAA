
#include <iostream>
using namespace std;

// NON-RECURSIVE FIBONACCI
void nonRecursive(int n) {
    int a = 0, b = 1, c;

    for (int i = 0; i <= n; i++) {
        cout << a << " ";

        c = a + b;
        a = b;
        b = c;
    }
}

// RECURSIVE FIBONACCI
int recursive(int n) {
    if (n <= 1)
        return n;

    return recursive(n - 1) + recursive(n - 2);
}

// RUN FIBONACCI
void run_fibo() {
    int n;

    cout << "Enter number of terms: ";
    cin >> n;

    if (n < 0) {
        cout << "Please enter a non-negative number.\n";
        return;
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
}

// TOWER OF HANOI
void towerOfHanoi(int n, char source,
                  char auxiliary, char destination) {

    if (n == 1) {
        cout << "Move disk 1 from " << source
             << " to " << destination << "\n";
        return;
    }

    towerOfHanoi(n - 1, source, destination, auxiliary);

    cout << "Move disk " << n << " from " << source
         << " to " << destination << "\n";

    towerOfHanoi(n - 1, auxiliary, source, destination);
}

// COUNT TOTAL MOVES
long long moveCount(int n) {
    return (1LL << n) - 1;
}

// RUN TOWER OF HANOI
void run_tower() {
    int n;

    cout << "\nEnter the number of disks: ";
    cin >> n;

    if (n < 1) {
        cout << "Number of disks must be at least 1.\n";
        return;
    }

    if (n > 25) {
        cout << "Please enter 25 or fewer disks.\n";
        return;
    }

    cout << "\nSequence of moves:\n";

    towerOfHanoi(n, 'A', 'B', 'C');

    cout << "\nTotal moves = " << moveCount(n) << "\n";

    cout << "\nTime and Space Complexity:\n";
    cout << "Time Complexity: O(2^n)\n";
    cout << "Space Complexity: O(n)\n";
}

// MAIN FUNCTION
int main() {
    run_fibo();
    run_tower();

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











// 2. Theory
// Tower of Hanoi is a mathematical puzzle consisting of three pegs (A, B, C) and n disks of different sizes.

// Initially, all disks are placed on peg A in decreasing order of size, with the largest disk at the bottom.

// Rules:
// 1. Only one disk can be moved at a time.
// 2. Only the top disk of a peg can be moved.
// 3. A larger disk cannot be placed on a smaller disk.
// 4. All disks must be transferred from source peg A to destination peg C using auxiliary peg B.
// 3. Algorithm
// 1. Start.
// 2. Read the number of disks n.
// 3. If n == 1, move the disk directly from source to destination.
// 4. Otherwise:
//    - Move n-1 disks from source to auxiliary using destination.
//    - Move the largest disk from source to destination.
//    - Move n-1 disks from auxiliary to destination using source.
// 5. Display all moves.
// 6. Calculate total moves using \(2^n-1\).
// 7. Stop.

// Q5. What is the time complexity?

// \(O(2^n)\).

// Q6. What is the space complexity?

// \(O(n)\).