#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to find the maximum subarray sum using Kadane's Algorithm
int maxSubArraySumKadane(const vector<int>& arr) {
    int max_sum = INT_MIN, current_sum = 0;
    for (int num : arr) {
        current_sum += num;
        if (current_sum > max_sum)
            max_sum = current_sum;
        if (current_sum < 0)
            current_sum = 0;
    }
    return max_sum;
}

int main() {
    int n;
    // Taking input for the size of the matrix
    cout << "Enter size of matrix (n x n): ";
    cin >> n;

    // Declaring a 2D vector to store the matrix elements
    vector<vector<int>> matrix(n, vector<int>(n));

    // Taking input for the matrix elements
    cout << "Enter the matrix elements:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    // Displaying the matrix
    cout << "\nThe input matrix is:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Finding the maximum subarray sum for each row using Kadane's Algorithm
    cout << "\nMaximum subarray sum for each row (Kadane's Algorithm):\n";
    for (int i = 0; i < n; i++) {
        int max_sum = maxSubArraySumKadane(matrix[i]);
        cout << "Row " << i + 1 << ": " << max_sum << endl;
    }

    return 0;
}
