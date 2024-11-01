#include <iostream>
#include <vector>

using namespace std;

void findMaxPartition(int n, vector<int>& current, vector<int>& result, int start) {
    if (n == 0 && current.size() > result.size()) {
        result = current;
        return;
    }
    for (int i = start; i <= n; i++) {
        current.push_back(i);
        findMaxPartition(n - i, current, result, i + 1);
        current.pop_back();
    }
}

vector<int> maxDistinctPartition(int n) {
    vector<int> result, current;
    findMaxPartition(n, current, result, 1);
    return result;
}

int main() {
    int n = 6;
    vector<int> partition = maxDistinctPartition(n);
    for (int part : partition) {
        cout << part << " ";
    }
    cout << endl;
    return 0;
}
