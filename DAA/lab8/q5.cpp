#include <iostream>
#include <vector>
using namespace std;

bool match2D(const vector<vector<char>>& T, const vector<vector<char>>& P, int x, int y) {
    int m = P.size();
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            if (T[x + i][y + j] != P[i][j]) return false;
    return true;
}

vector<pair<int, int>> stringMatching2D(const vector<vector<char>>& T, const vector<vector<char>>& P) {
    int n = T.size(), m = P.size();
    vector<pair<int, int>> matches;
    for (int i = 0; i <= n - m; i++)
        for (int j = 0; j <= n - m; j++)
            if (match2D(T, P, i, j)) matches.push_back({i, j});
    return matches;
}
