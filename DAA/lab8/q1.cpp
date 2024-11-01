#include <iostream>
#include <vector>
using namespace std;

vector<int> computeValidShifts(string T, string P) {
    vector<int> shifts;
    int n = T.size(), m = P.size();
    for (int s = 0; s <= n - m; s++) {
        bool match = true;
        for (int i = 0; i < m; i++) {
            if (P[i] != ' ' && T[s + i] != P[i]) {
                match = false;
                break;
            }
        }
        if (match) shifts.push_back(s);
    }
    return shifts;
}
