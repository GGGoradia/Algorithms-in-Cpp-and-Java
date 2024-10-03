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

int brute_force_max_subarray(const vector<int>& arr) {
    int max_sum = arr[0];
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        int current_sum = 0;
        for (int j = i; j < n; ++j) {
            current_sum += arr[j];
            if (current_sum > max_sum) {
                max_sum = current_sum;
            }
        }
    }
    return max_sum;
}

void run_brute_force(int n) {
    vector<int> arr = generate_random_array(n);

    clock_t start_time = clock();

    cout << "Brute force for n = " << n << ": ";
    int max_sum = brute_force_max_subarray(arr);

    clock_t end_time = clock();
    double time_taken = double(end_time - start_time) / CLOCKS_PER_SEC;

    cout << "Max sum = " << max_sum << " | Time taken = " << time_taken << " seconds" << endl;
}

int main() {
    vector<int> sizes = {10, 100, 1000,10000,100000};

    for (int n : sizes) {
        run_brute_force(n);
        cout << endl;
    }

    return 0;
}
