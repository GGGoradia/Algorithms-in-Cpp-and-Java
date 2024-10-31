#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Activity {
    int start, finish, value;
};

bool compareActivity(Activity a1, Activity a2) {
    return a1.finish < a2.finish;
}

int latestNonConflict(vector<Activity>& activities, int i) {
    for (int j = i - 1; j >= 0; j--) {
        if (activities[j].finish <= activities[i].start) {
            return j;
        }
    }
    return -1;
}

int findMaxValueSubset(vector<Activity>& activities) {
    sort(activities.begin(), activities.end(), compareActivity);

    int n = activities.size();
    vector<int> dp(n);

    dp[0] = activities[0].value;

    for (int i = 1; i < n; i++) {
        int incl = activities[i].value;
        int l = latestNonConflict(activities, i);
        if (l != -1) {
            incl += dp[l];
        }
        dp[i] = max(incl, dp[i - 1]);
    }

    return dp[n - 1];
}

int main() {
    vector<Activity> activities = {{1, 3, 5}, {2, 5, 6}, {4, 6, 5}, {6, 7, 4}, {5, 8, 11}, {7, 9, 2}};

    cout << "Maximum value subset: " << findMaxValueSubset(activities) << endl;

    return 0;
}
