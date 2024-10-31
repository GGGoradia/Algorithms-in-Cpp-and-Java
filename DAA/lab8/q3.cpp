#include <iostream>
#include <vector>

using namespace std;

bool isSafe(int v, vector<vector<int>>& graph, vector<int>& colors, int c) {
    for (int i = 0; i < graph.size(); i++) {
        if (graph[v][i] && colors[i] == c) return false;
    }
    return true;
}

bool graphColoringUtil(vector<vector<int>>& graph, int m, vector<int>& colors, int v) {
    if (v == graph.size()) return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, colors, c)) {
            colors[v] = c;
            if (graphColoringUtil(graph, m, colors, v + 1)) return true;
            colors[v] = 0;
        }
    }
    return false;
}

bool graphColoring(vector<vector<int>>& graph, int m) {
    vector<int> colors(graph.size(), 0);
    return graphColoringUtil(graph, m, colors, 0);
}

int main() {
    vector<vector<int>> graph = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    int m = 3;
    if (graphColoring(graph, m)) {
        cout << "Solution exists." << endl;
    } else {
        cout << "No solution exists." << endl;
    }

    return 0;
}
