#include <iostream>
#include <vector>

using namespace std;

bool subsetSumUtil(vector<int>& set, vector<int>& subset, int index, int k, int sum) {
    if (sum == k) {
        for (int num : subset) cout << num << " ";
        cout << endl;
        return true;
    }
    if (index == set.size() || sum > k) return false;

    subset.push_back(set[index]);
    if (subsetSumUtil(set, subset, index + 1, k, sum + set[index])) return true;

    subset.pop_back();
    return subsetSumUtil(set, subset, index + 1, k, sum);
}

void subsetSum(vector<int>& set, int k) {
    vector<int> subset;
    subsetSumUtil(set, subset, 0, k, 0);
}

int main() {
    vector<int> set = {3, 34, 4, 12, 5, 2};
    int k = 9;
    subsetSum(set, k);
    return 0;
}
