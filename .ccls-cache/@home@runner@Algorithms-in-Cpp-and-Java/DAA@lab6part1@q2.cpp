#include <iostream>
#include <string>

using namespace std;

int LCS(const string &X, const string &Y, int m, int n) {
    if (m == 0 || n == 0) {
        return 0;
    }
    if (X[m - 1] == Y[n - 1]) {
        return 1 + LCS(X, Y, m - 1, n - 1);
    } else {
        return max(LCS(X, Y, m, n - 1), LCS(X, Y, m - 1, n));
    }
}

int main() {
    string X, Y;
    
    cout << "Enter the first sequence (X): ";
    cin >> X;
    
    cout << "Enter the second sequence (Y): ";
    cin >> Y;
    
    int m = X.length();
    int n = Y.length();
    
    int length_of_LCS = LCS(X, Y, m, n);
    
    cout << "The length of the longest common subsequence is: " << length_of_LCS << endl;
    
    return 0;
}
