#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to find the maximum subarray sum using the brute force approach
int maxSubArraySumBruteForce(const vector<int>& arr) {
    int n = arr.size();
    int max_sum = INT_MIN;

    // Try every possible subarray
    for (int i = 0; i < n; i++) {
        int current_sum = 0;
        for (int j = i; j < n; j++) {
            current_sum += arr[j];
            max_sum = max(max_sum, current_sum);
        }
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

    // Finding the maximum subarray sum for each row using the brute force approach
    cout << "\nMaximum subarray sum for each row (Brute Force):\n";
    for (int i = 0; i < n; i++) {
        int max_sum = maxSubArraySumBruteForce(matrix[i]);
        cout << "Row " << i + 1 << ": " << max_sum << endl;
    }

    return 0;
}
