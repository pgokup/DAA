#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

// One knapsack item: its value, its weight, and its value-per-unit ratio.
struct Item {
    double value;
    double weight;
    double ratio;
};

// Read all items and the capacity from standard input.
vector<Item> readItems(int itemCount) {
    vector<Item> items(itemCount);

    cout << "Enter value and weight of each item:\n";
    for (int i = 0; i < itemCount; ++i) {
        cout << "Item " << (i + 1) << " value: ";
        cin >> items[i].value;
        cout << "Item " << (i + 1) << " weight: ";
        cin >> items[i].weight;
        items[i].ratio = items[i].value / items[i].weight;  // the "deal quality"
    }
    return items;
}

// Sort items so the best value/weight ratio comes first (greedy order).
void sortByRatio(vector<Item>& items) {
    sort(items.begin(), items.end(),
         [](const Item& a, const Item& b) { return a.ratio > b.ratio; });
}

// Core greedy algorithm: take whole items while they fit, then a fraction.
double fillKnapsack(vector<Item> items, double capacity) {
    sortByRatio(items);

    double totalValue = 0.0;
    double remaining = capacity;

    cout << "\nSelected Items:\n";
    for (size_t i = 0; i < items.size(); ++i) {
        if (remaining <= 0) break;  // knapsack is full -> stop

        if (items[i].weight <= remaining) {
            // Whole item fits: take 100% of it.
            remaining -= items[i].weight;
            totalValue += items[i].value;
            cout << "Item " << (i + 1) << " -> 100% selected\n";
        } else {
            // Item does not fit: take the fraction of it that fits.
            double fraction = remaining / items[i].weight;
            totalValue += items[i].value * fraction;
            cout << "Item " << (i + 1) << " -> " << fixed << setprecision(2)
                 << fraction * 100 << "% selected\n";
            remaining = 0;
        }
    }
    return totalValue;
}

// Drives the whole practical; main() only calls this.
void run() {
    int itemCount;
    cout << "Enter number of items: ";
    cin >> itemCount;

    vector<Item> items = readItems(itemCount);

    double capacity;
    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    double maxValue = fillKnapsack(items, capacity);

    cout << fixed << setprecision(2);
    cout << "\nMaximum value = " << maxValue << "\n";
}

int main() {
    run();
    return 0;
}










































































// What is Fractional Knapsack?
// Fractional Knapsack is a problem in which we have items with different values and weights, and a bag with limited capacity.

// We can take:
// - The complete item.
// - A fraction of an item.
// Our objective is to obtain the maximum total value.
// 2. Greedy Strategy
// The algorithm works in 4 steps:
// 5. Algorithm (Important for Practical Exam)
// The algorithm for Fractional Knapsack using Greedy Method is:
// 1. Start.
// 2. Read the number of items.
// 3. Read the value and weight of each item.
// 4. Calculate the value-to-weight ratio of every item.
// 5. Sort all items in descending order of their ratios.
// 6. Initialize total value to zero and remaining capacity to the knapsack capacity.
// 7. Traverse each item:
//    - If the item's weight is less than or equal to the remaining capacity, select the complete item.
//    - Otherwise, select the fraction that fits into the remaining capacity.
// 8. Update the total value.
// 9. Display the maximum total value.
// 10. Stop.


// 4. Time and Space Complexity
// Operation	Complexity
// Calculate ratio	O(n)
// Sorting	O(n log n)
// Selection	O(n)
// Total time	O(n log n)
// Space	O(n)


// 9. Real-Life Applications
// Fractional Knapsack can be applied in situations where resources can be divided.
// 1. Gold and jewellery: Selecting a certain quantity of gold based on its value and weight.
// 2. Cargo loading: Selecting quantities of divisible goods for transportation.
// 3. Resource allocation: Distributing limited resources to maximize total benefit.
// 4. Investment allocation: Allocating divisible funds among opportunities under simplified return assumptions.