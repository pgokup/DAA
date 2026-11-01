#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> board;

// Check whether queen can be placed safely
bool isSafe(int row, int col)
{
    // Check column
    for(int i = 0; i < row; i++)
        if(board[i][col] == 1)
            return false;

    // Check upper-left diagonal
    for(int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--)
        if(board[i][j] == 1)
            return false;

    // Check upper-right diagonal
    for(int i = row-1, j = col+1; i >= 0 && j < n; i--, j++)
        if(board[i][j] == 1)
            return false;

    return true;
}

// Solve N-Queens using backtracking
bool solveNQueens(int row)
{
    // All queens are placed
    if(row == n)
        return true;

    // First queen is already placed
    if(row == 0)
        return solveNQueens(row + 1);

    // Try every column
    for(int col = 0; col < n; col++)
    {
        if(isSafe(row, col))
        {
            board[row][col] = 1;

            if(solveNQueens(row + 1))
                return true;

            // Backtracking
            board[row][col] = 0;
        }
    }

    return false;
}

// Display solution matrix
void printBoard()
{
    cout << "\nSolution Matrix:\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout << board[i][j] << " ";

        cout << endl;
    }
}

int main()
{
    cout << "Enter the value of N: ";
    cin >> n;

    if(n < 1)
    {
        cout << "N must be at least 1.";
        return 0;
    }

    board.assign(n, vector<int>(n, 0));

    // Place first queen at (0,0)
    board[0][0] = 1;

    if(solveNQueens(0))
        printBoard();
    else
        cout << "No solution exists with the first queen at (0,0).";

    return 0;
}






































































// 2. Theory
// The N-Queens problem is a classic problem solved using the Backtracking technique. The objective is to place N queens on an N × N chessboard such that no two queens attack each other.

// A queen can attack another queen horizontally, vertically and diagonally. Therefore, the following conditions must be satisfied:
// 1. No two queens should be in the same row.
// 2. No two queens should be in the same column.
// 3. No two queens should be on the same diagonal.
// Backtracking approach:
// 1. First, place a queen at position (0,0).
// 2. Start placing the remaining queens row by row.
// 3. Check whether the selected position is safe.
// 4. If the position is safe, place the queen and move to the next row.
// 5. If no safe position is available, remove the previously placed queen and try another position. This process is called backtracking.
// 6. When all N queens are successfully placed, the solution is obtained.
// 3. Algorithm
// 1. Start.
// 2. Read the value of N.
// 3. Create an N × N matrix initialized with 0.
// 4. Place the first queen at position (0,0).
// 5. Check whether the current position is safe by checking its column and both diagonals.
// 6. If safe, place the queen and recursively solve the next row.
// 7. If no safe position is available, backtrack by removing the previously placed queen.
// 8. If all queens are placed successfully, print the solution matrix.
// 9. Otherwise, display "No solution exists".
// 10. Stop.


// 6. Time and Space Complexity
// Complexity	Value
// Time Complexity	O(N!) approximately (worst-case search)
// Space Complexity	O(N²) for the board
// Recursion Space	O(N)



// 8. Advantages
// 1. Uses a systematic approach to find a valid solution.
// 2. Avoids checking invalid arrangements unnecessarily.
// 3. Demonstrates recursion and backtracking.
// 4. Can solve different sizes of chessboards.
// 5. Useful for understanding constraint satisfaction problems.

// 9. Applications
// 1. Chessboard and puzzle-solving problems.
// 2. Constraint satisfaction problems.
// 3. Resource allocation.
// 4. Scheduling problems.
// 5. Combinatorial optimization.

// 10. Limitations
// 1. Execution time increases as the value of N increases.
// 2. Backtracking may explore many possible arrangements.
// 3. Some board sizes do not have a valid solution.
// 4. Fixing the first queen at (0,0) can eliminate solutions that would otherwise exist.