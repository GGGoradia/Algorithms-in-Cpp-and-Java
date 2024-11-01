#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int rodCutting(int n, const vector<int> &prices) {
    if (n == 0) return 0;
    int maxRevenue = INT_MIN;
    for (int i = 1; i <= n; i++) {
        maxRevenue = max(maxRevenue, prices[i] + rodCutting(n - i, prices));
    }
    return maxRevenue;
}

int main() {
    int n;
    cout << "Enter the length of the rod: ";
    cin >> n;

    vector<int> prices(n + 1);
    cout << "Enter the prices for lengths 1 to " << n << ": ";
    for (int i = 1; i <= n; i++) {
        cin >> prices[i];
    }

    int maxRevenue = rodCutting(n, prices);
    cout << "Maximum Revenue: " << maxRevenue << endl;

    return 0;
}
