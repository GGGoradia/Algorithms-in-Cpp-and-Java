#include <iostream>
#include <vector>
#include <string>

using namespace std;

void computeLCS(const string &X, const string &Y) {
    int m = X.length();
    int n = Y.length();
    
    vector<vector<int>> c(2, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                c[i % 2][j] = c[(i - 1) % 2][j - 1] + 1;
            } else {
                c[i % 2][j] = max(c[(i - 1) % 2][j], c[i % 2][j - 1]);
            }
        }
    }

    int length_of_LCS = c[m % 2][n];
    cout << "Length of LCS: " << length_of_LCS << endl;

    int index = length_of_LCS;
    string lcs(index, ' ');
    int i = m, j = n;

    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        } else if (c[(i - 1) % 2][j] > c[i % 2][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    cout << "The Longest Common Subsequence is: " << lcs << endl;
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
