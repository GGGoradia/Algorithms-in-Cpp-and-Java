#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> multiTextMultiPattern(vector<string> texts, vector<string> patterns) {
    vector<vector<int>> results;
    for (const auto& text : texts) {
        vector<int> validShifts;
        for (const auto& pattern : patterns) {
            int m = pattern.size(), n = text.size(), pHash = 0, tHash = 0, p = 31, mod = 1e9 + 7, pow_p = 1;
            for (int i = 0; i < m; i++) {
                pHash = (pHash * p + pattern[i]) % mod;
                tHash = (tHash * p + text[i]) % mod;
                if (i < m - 1) pow_p = (pow_p * p) % mod;
            }
            for (int i = 0; i <= n - m; i++) {
                if (pHash == tHash) validShifts.push_back(i);
                if (i < n - m) {
                    tHash = (tHash - text[i] * pow_p % mod + mod) % mod;
                    tHash = (tHash * p + text[i + m]) % mod;
                }
            }
        }
        results.push_back(validShifts);
    }
    return results;
}
