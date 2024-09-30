#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// Function to calculate minimum matrix chain multiplication cost
int mcm(int i, int j, vector<int>& arr) {
    if(i == j) {
        return 0; // No cost if there's only one matrix
    }
    
    int mini = INT_MAX;

    // Try partitioning the chain at every possible position
    for(int k = i; k < j; k++) {
        // Recursive step: cost of multiplying matrices from i to k and k+1 to j
        int steps = arr[i-1] * arr[k] * arr[j] 
                    + mcm(i, k, arr) 
                    + mcm(k+1, j, arr);

        // Update the minimum cost
        mini = min(mini, steps);
    }

    return mini; // Return the minimum number of scalar multiplications
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 50}; // Matrix dimensions
    int n = arr.size();

    // Call mcm() with the starting and ending indices
    cout << "Minimum number of multiplications: " << mcm(1, n-1, arr) << endl;
    return 0;
}
