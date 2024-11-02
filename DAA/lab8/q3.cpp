#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

vector<int> rabinKarpMultiPatterns(const string& T, const vector<string>& P) {
    int n = T.size();
    set<int> uniqueShifts;  // Use a set to avoid duplicates
    int p = 31, mod = 1e9 + 7;
    
    for (const auto& pattern : P) {
        int m = pattern.size();
        int patternHash = 0, textHash = 0, pow_p = 1;

        // Compute initial hashes and power of p^(m-1)
        for (int i = 0; i < m; i++) {
            patternHash = (patternHash * p + pattern[i]) % mod;
            textHash = (textHash * p + T[i]) % mod;
            if (i < m - 1) pow_p = (pow_p * p) % mod;
        }

        // Sliding window over text
        for (int i = 0; i <= n - m; i++) {
            if (patternHash == textHash && T.substr(i, m) == pattern) {
                uniqueShifts.insert(i);  // Insert position into set
            }
            
            if (i < n - m) {
                textHash = (textHash - T[i] * pow_p % mod + mod) % mod;
                textHash = (textHash * p + T[i + m]) % mod;
            }
        }
    }
    
    // Convert set to vector for returning
    return vector<int>(uniqueShifts.begin(), uniqueShifts.end());
}

int main() {
    string T = "ababcababc";
    vector<string> P = {"ab", "abc"};
    
    vector<int> matches = rabinKarpMultiPatterns(T, P);
    
    cout << "Pattern found at positions: ";
    for (int pos : matches) {
        cout << pos << " ";
    }
    cout << endl;
    
    return 0;
}
