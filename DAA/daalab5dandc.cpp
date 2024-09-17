#include <iostream>
#include <vector>
#include <climits>
#include <ctime>

using namespace std;

// Function to find the maximum sum crossing the middle
int max_crossing_sum(const vector<int>& arr, int left, int mid, int right) {
    int left_sum = INT_MIN;
    int sum = 0;

    // Calculate maximum sum of subarray on the left of mid
    for (int i = mid; i >= left; i--) {
        sum += arr[i];
        if (sum > left_sum) {
            left_sum = sum;
        }
    }

    int right_sum = INT_MIN;
    sum = 0;

    // Calculate maximum sum of subarray on the right of mid
    for (int i = mid + 1; i <= right; i++) {
        sum += arr[i];
        if (sum > right_sum) {
            right_sum = sum;
        }
    }

    // Return sum of elements on left and right of mid
    return left_sum + right_sum;
}

// Recursive function to find the maximum subarray sum
int divide_and_conquer_max_subarray(const vector<int>& arr, int left, int right) {
    // Base case: only one element
    if (left == right) {
        return arr[left];
    }

    // Find middle point
    int mid = left + (right - left) / 2;

    // Recursively find the maximum subarray sum in left half, right half, and crossing mid
    int left_sum = divide_and_conquer_max_subarray(arr, left, mid);
    int right_sum = divide_and_conquer_max_subarray(arr, mid + 1, right);
    int cross_sum = max_crossing_sum(arr, left, mid, right);

    // Return the maximum of the three cases
    return max(max(left_sum, right_sum), cross_sum);
}

void run_divide_and_conquer(int n) {
    vector<int> arr(n);
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 20001 - 10000; // Generate random values between -10000 and 10000
    }

    clock_t start_time = clock();

    cout << "Divide and Conquer for n = " << n << ": ";
    int max_sum = divide_and_conquer_max_subarray(arr, 0, n - 1);

    clock_t end_time = clock();
    double time_taken = double(end_time - start_time) / CLOCKS_PER_SEC;

    cout << "Max sum = " << max_sum << " | Time taken = " << time_taken << " seconds" << endl;
}

int main() {
    vector<int> sizes = {10, 100, 1000,10000,100000};

    for (int n : sizes) {
        run_divide_and_conquer(n);
        cout << endl;
    }

    return 0;
}   
