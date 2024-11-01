#include <iostream>
#include <vector>
using namespace std;

vector<int> prefixFunction(string s) {
    int n = s.size();
    vector<int> pi(n);
    for (int i = 1, j = 0; i < n; i++) {
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

vector<int> validShiftsUsingPrefix(string P, string T) {
    vector<int> shifts;
    vector<int> pi = prefixFunction(P + "#" + T);
    int m = P.size();
    for (int i = m + 1; i < pi.size(); i++) {
        if (pi[i] == m) shifts.push_back(i - 2 * m);
    }
    return shifts;
}
