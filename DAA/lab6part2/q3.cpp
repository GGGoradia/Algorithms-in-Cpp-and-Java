#include <iostream>
#include <vector>

using namespace std;

int fiba_helper(int n, vector<int> &memo) {
    if (n == 1) return 0;
    if (n == 2) return 1;
    if (n == 3) return 2;

    if (memo[n] != -1) return memo[n];

    memo[n] = fiba_helper(n - 1, memo) + fiba_helper(n - 2, memo) + fiba_helper(n - 3, memo);
    return memo[n];
}

int fiba(int n) {
    vector<int> memo(n + 1, -1);
    return fiba_helper(n, memo);
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int result = fiba(n);
    cout << "fiba(" << n << ") = " << result << endl;

    return 0;
}
