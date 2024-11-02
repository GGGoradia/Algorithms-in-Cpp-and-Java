#include <iostream>
#include <vector>
using namespace std;

int hash2D(const vector<vector<char>>& arr, int x, int y, int m) {
    int hashValue = 0, p = 31, mod = 1e9 + 7;
    for (int i = x; i < x + m; i++) {
        for (int j = y; j < y + m; j++) {
            hashValue = (hashValue * p + arr[i][j]) % mod;
        }
    }
    return hashValue;
}

vector<pair<int, int>> rabinKarp2D(const vector<vector<char>>& T, const vector<vector<char>>& P) {
    int n = T.size(), m = P.size();
    vector<pair<int, int>> result;
    int patternHash = hash2D(P, 0, 0, m);
    
    for (int i = 0; i <= n - m; i++) {
        for (int j = 0; j <= n - m; j++) {
            if (hash2D(T, i, j, m) == patternHash) result.push_back({i, j});
        }
    }
    return result;
}

int main() {
    vector<vector<char>> T = {
        {'a', 'b', 'a', 'b'},
        {'a', 'b', 'a', 'b'},
        {'a', 'b', 'a', 'b'},
        {'a', 'b', 'a', 'b'}
    };
    
    vector<vector<char>> P = {
        {'a', 'b'},
        {'a', 'b'}
    };
    
    vector<pair<int, int>> matches = rabinKarp2D(T, P);
    
    cout << "Pattern found at positions:\n";
    for (const auto& pos : matches) {
        cout << "(" << pos.first << ", " << pos.second << ")\n";
    }
    
    return 0;
}
