#include <iostream>
#include <vector>

using namespace std;

// Function to solve 0/1 Knapsack using dynamic programming
int knapsack(int W, vector<int>& weights, vector<int>& values, int n) {
    // DP table to store the maximum value for each capacity
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weights[i-1] <= w) {
                // Maximum of either including the item or excluding it
                dp[i][w] = max(dp[i-1][w], dp[i-1][w-weights[i-1]] + values[i-1]);
            } else {
                // Exclude the item if it cannot be included due to weight
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    // The value of the knapsack with capacity W and n items is the bottom-right corner of the table
    return dp[n][W];
}

int main() {
    int n = 4;  // Number of items
    int W = 7;  // Capacity of knapsack

    // Weights of the items
    vector<int> weights = {1, 3, 4, 5};

    // Values of the items
    vector<int> values = {1, 4, 5, 7};

    // Call the knapsack function
    int max_value = knapsack(W, weights, values, n);

    cout << "Maximum value in Knapsack = " << max_value << endl;

    return 0;
}
