#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int rodCutting(const vector<int> &prices, int n) {
    vector<int> r(n + 1, 0);
    
    for (int j = 1; j <= n; j++) {
        int maxRevenue = INT_MIN;
        for (int i = 1; i <= j; i++) {
            maxRevenue = max(maxRevenue, prices[i] + r[j - i]);
        }
        r[j] = maxRevenue;
    }
    
    return r[n];
}

int main() {
    int n;
    cout << "Enter the length of the rod: ";
    cin >> n;

    vector<int> prices(n + 1);
    cout << "Enter the prices for each length (1 to " << n << "): ";
    for (int i = 1; i <= n; i++) {
        cin >> prices[i];
    }

    int maxRevenue = rodCutting(prices, n);
    cout << "Maximum revenue obtainable: " << maxRevenue << endl;

    return 0;
}
