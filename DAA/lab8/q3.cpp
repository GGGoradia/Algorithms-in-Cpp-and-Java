#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> rabinKarpMultiPatterns(string T, vector<string> P) {
    int n = T.size();
    vector<int> validShifts;
    for (auto& pattern : P) {
        int m = pattern.size();
        int patternHash = 0, textHash = 0, p = 31, mod = 1e9 + 7, pow_p = 1;
        for (int i = 0; i < m; i++) {
            patternHash = (patternHash * p + pattern[i]) % mod;
            textHash = (textHash * p + T[i]) % mod;
            if (i < m - 1) pow_p = (pow_p * p) % mod;
        }
        for (int i = 0; i <= n - m; i++) {
            if (patternHash == textHash) validShifts.push_back(i);
            if (i < n - m) {
                textHash = (textHash - T[i] * pow_p % mod + mod) % mod;
                textHash = (textHash * p + T[i + m]) % mod;
            }
        }
    }
    return validShifts;
}
