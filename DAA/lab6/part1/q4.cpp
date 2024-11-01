#include <iostream>
#include <vector>
#include <string>

using namespace std;

int LCS(const string &X, const string &Y, int m, int n, vector<vector<int>> &memo) {
    if (m == 0 || n == 0) {
        return 0;
    }

    if (memo[m][n] != -1) {
        return memo[m][n];
    }

    if (X[m - 1] == Y[n - 1]) {
        memo[m][n] = 1 + LCS(X, Y, m - 1, n - 1, memo);
    } else {
        memo[m][n] = max(LCS(X, Y, m, n - 1, memo), LCS(X, Y, m - 1, n, memo));
    }

    return memo[m][n];
}

void computeLCS(const string &X, const string &Y) {
    int m = X.length();
    int n = Y.length();
    
    vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));

    int length_of_LCS = LCS(X, Y, m, n, memo);

    cout << "Memoization Table:\n";
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            cout << memo[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Length of LCS: " << length_of_LCS << endl;
}

int main() {
    string X, Y;

    cout << "Enter the first sequence (X): ";
    cin >> X;

    cout << "Enter the second sequence (Y): ";
    cin >> Y;

    computeLCS(X, Y);
    
    return 0;
}
