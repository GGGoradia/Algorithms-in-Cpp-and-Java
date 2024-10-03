#include <iostream>
#include <vector>
#include <cstdlib>
#include <climits>
#include <ctime>

using namespace std;

vector<int> generate_random_array(int n) {
    vector<int> arr(n);
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 20001 - 10000;
    }
    return arr;
}

int kadane_max_subarray(const vector<int>& arr) {
    int max_current = arr[0];
    int max_global = arr[0];
    int n = arr.size();

    for (int i = 1; i < n; ++i) {
        max_current = max(arr[i], max_current + arr[i]);
        if (max_current > max_global) {
            max_global = max_current;
        }
    }

    return max_global;
}

void run_kadane(int n) {
    vector<int> arr = generate_random_array(n);

    clock_t start_time = clock();

    cout << "Kadane's Algorithm for n = " << n << ": ";
    int max_sum = kadane_max_subarray(arr);

    clock_t end_time = clock();
    double time_taken = double(end_time - start_time) / CLOCKS_PER_SEC;

    cout << "Max sum = " << max_sum << " | Time taken = " << time_taken << " seconds" << endl;
}

int main() {
    vector<int> sizes = {10, 100, 1000, 10000, 100000};

    for (int n : sizes) {
        run_kadane(n);
        cout << endl;
    }

    return 0;
}
