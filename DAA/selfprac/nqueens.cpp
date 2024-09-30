#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int row, int col, vector<string>& board, int n) {
    for (int i = 0; i < col; i++)
        if (board[row][i] == 'Q')
            return false;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q')
            return false;
    for (int i = row, j = col; i < n && j >= 0; i++, j--)
        if (board[i][j] == 'Q')
            return false;
    return true;
}

void solve(int col, vector<string>& board, vector<vector<string>>& solutions, int n) {
    if (col == n) {
        solutions.push_back(board);
        return;
    }
    for (int row = 0; row < n; row++) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = 'Q';
            solve(col + 1, board, solutions, n);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> solutions;
    vector<string> board(n, string(n, '.'));
    solve(0, board, solutions, n);
    return solutions;
}

int main() {
    int n = 4;
    vector<vector<string>> solutions = solveNQueens(n);
    for (auto solution : solutions) {
        for (auto row : solution)
            cout << row << endl;
        cout << endl;
    }
    return 0;
}
