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

int main() {
    vector<vector<char>> T = {
        {'a', 'b', 'a', 'b'},
        {'b', 'a', 'b', 'a'},
        {'a', 'b', 'a', 'b'},
        {'b', 'a', 'b', 'a'}
    };

    vector<vector<char>> P = {
        {'a', 'b'},
        {'b', 'a'}
    };

    vector<pair<int, int>> matches = stringMatching2D(T, P);

    cout << "Pattern found at positions: ";
    for (auto match : matches) {
        cout << "(" << match.first << ", " << match.second << ") ";
    }
    cout << endl;

    return 0;
}
