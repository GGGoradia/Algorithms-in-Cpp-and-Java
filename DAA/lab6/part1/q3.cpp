#include <iostream>
#include <vector>
#include <string>

using namespace std;

void LCS(const string &X, const string &Y) {
    int m = X.length();
    int n = Y.length();
    
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << "DP Table:\n";
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    int length_of_LCS = dp[m][n];
    cout << "Length of LCS: " << length_of_LCS << endl;

    string LCS_string = "";
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            LCS_string = X[i - 1] + LCS_string;
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    cout << "The longest common subsequence is: " << LCS_string << endl;
}

int main() {
    string X, Y;

    cout << "Enter the first sequence (X): ";
    cin >> X;

    cout << "Enter the second sequence (Y): ";
    cin >> Y;

    LCS(X, Y);
    
    return 0;
}
