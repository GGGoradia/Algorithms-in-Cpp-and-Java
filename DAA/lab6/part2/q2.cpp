#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int editDistance(const string &A, const string &B) {
    int m = A.length();
    int n = B.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (int i = 0; i <= m; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
            }
        }
    }

    return dp[m][n];
}

int main() {
    string A, B;
    cout << "Enter first string: ";
    cin >> A;
    cout << "Enter second string: ";
    cin >> B;

    int distance = editDistance(A, B);
    cout << "Minimum Edit Distance: " << distance << endl;

    return 0;
}
