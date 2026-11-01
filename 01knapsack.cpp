#include <iostream>
#include <vector>

using namespace std;

// Read all item values and weights from standard input.
void readItems(int itemCount, vector<long long>& value, vector<int>& weight) {
    cout << "Enter value and weight of each item:\n";
    for (int i = 0; i < itemCount; ++i) {
        cout << "Item " << (i + 1) << " value: ";
        cin >> value[i];
        cout << "Item " << (i + 1) << " weight: ";
        cin >> weight[i];
    }
}

// Fill the DP table and return dp[n][capacity] (the maximum value).
long long buildTable(const vector<long long>& value, const vector<int>& weight,
                     vector<vector<long long>>& dp, int itemCount, int capacity) {
    for (int i = 1; i <= itemCount; ++i) {
        for (int w = 0; w <= capacity; ++w) {
            if (weight[i - 1] <= w) {
                // Option A: keep the best without item i.
                long long without = dp[i - 1][w];
                // Option B: take item i (its weight must come out of w first).
                long long with_ = value[i - 1] + dp[i - 1][w - weight[i - 1]];
                dp[i][w] = max(without, with_);
            } else {
                // Item i is too heavy for capacity w: cannot take it.
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[itemCount][capacity];
}

//This function identifies which items were selected in the optimal solution.
void printSelectedItems(const vector<long long>& value, const vector<int>& weight,
                        const vector<vector<long long>>& dp, int itemCount,
                        int capacity) {
    cout << "Selected items:\n";
    int w = capacity;
    for (int i = itemCount; i > 0; --i) {
        // Value changed between row i-1 and row i => item i was taken.
        if (dp[i][w] != dp[i - 1][w]) {
            cout << "Item " << i << " (value=" << value[i - 1]
                 << ", weight=" << weight[i - 1] << ")\n";
            w -= weight[i - 1];  // free the space the item occupied
        }
    }
}

// Drives the whole practical; main() only calls this.
void run() {
    int itemCount;
    cout << "Enter number of items: ";
    cin >> itemCount;

    vector<long long> value(itemCount);
    vector<int> weight(itemCount);
    readItems(itemCount, value, weight);

    int capacity;
    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    // dp[i][w] has n+1 rows (0 items ... n items) and W+1 columns (0 ... W).
    vector<vector<long long>> dp(itemCount + 1,
                                 vector<long long>(capacity + 1, 0));

    long long maxValue = buildTable(value, weight, dp, itemCount, capacity);

    cout << "\nMaximum value = " << maxValue << "\n";
    printSelectedItems(value, weight, dp, itemCount, capacity);
}

int main() {
    run();
    return 0;
}


























































































































// Working of `buildTable()` function:

// 1. The outer loop selects items one by one.
// 2. The inner loop checks every possible knapsack capacity.
// 3. The `if` condition checks whether the current item fits.
// 4. If it fits, the algorithm calculates two options:
//    - `without`: Maximum value without taking the item.
//    - `with_`: Maximum value by taking the item.
// 5. `max()` selects the option with the higher value and stores it in the DP table.
// 6. If the item does not fit, the previous value is copied.
// 7. Finally, it returns `dp[itemCount][capacity]`, which contains the maximum possible value.


// Working of `printSelectedItems()` function

// 1. Displays the heading Selected Items.
// 2. Starts from the maximum knapsack capacity.
// 3. Traverses the DP table backwards, starting from the last item.
// 4. Compares the current row with the previous row.
// 5. If values are different, the current item is selected.
// 6. Prints the selected item's value and weight.
// 7. Subtracts the selected item's weight from the remaining capacity.
// 8. Repeats until all items are checked.







// Enter value and weight of each item:
// Item 1 value: 2
// Item 1 weight: 3
// Item 2 value: 3
// Item 2 weight: 4
// Item 3 value: 1
// Item 3 weight: 6
// Item 4 value: 4
// Item 4 weight: 5
// Enter knapsack capacity: 8

// Maximum value = 6
// Selected items:
// Item 4 (value=4, weight=5)
// Item 1 (value=2, weight=3)


// . Theory
// The 0-1 Knapsack problem is an optimization problem in which we are given a set of items, each having a weight and a value, and a knapsack with a fixed capacity.

// The objective is to select items such that the total value is maximum without exceeding the knapsack capacity. Each item can either be selected completely (1) or rejected (0). Items cannot be divided into fractions.

// Dynamic Programming solves this problem by dividing it into smaller subproblems and storing their results in a table to avoid repeated calculations.

// The DP table is represented as dp[i][w], where i represents the number of items considered and w represents the current knapsack capacity.

// The recurrence relation is:
// \[
// dp[i][w] = \max(dp[i-1][w],\ value[i-1]+dp[i-1][w-weight[i-1]])
// \]

// If the item's weight exceeds the current capacity:
// \[
// dp[i][w] = dp[i-1][w]
// \]

// Finally, dp[n][W] gives the maximum value that can be obtained.
// 3. Algorithm
// 1. Start.
// 2. Accept the number of items.
// 3. Enter the value and weight of each item.
// 4. Enter the knapsack capacity.
// 5. Initialize the DP table with zeros.
// 6. For each item, check whether it can fit into the knapsack.
// 7. Calculate the maximum value by either selecting or rejecting the item.
// 8. Store the maximum value in the DP table.
// 9. Display the maximum value.
// 10. Trace the DP table to identify selected items.
// 11. Stop.






// 7. Complexity Analysis
// Complexity	Value
// Best-case time	O(n × W)
// Average-case time	O(n × W)
// Worst-case time	O(n × W)
// Space complexity	O(n × W)





// 7. Advantages
// 1. It guarantees an optimal solution for the standard 0-1 Knapsack problem.
// 2. It avoids repeated calculations by storing previously computed results.
// 3. It is more efficient than the basic recursive approach for many inputs.
// 4. It can identify the selected items as well as the maximum value.
// 8. Applications
// 1. Resource allocation in project management.
// 2. Budget optimization and investment selection.
// 3. Cargo loading and transportation.
// 4. Memory and storage allocation.
// 5. Selecting projects under limited resources.