#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Activity {
    int start, finish;
};

// Comparator to sort activities by finish time
bool compareActivity(Activity a1, Activity a2) {
    return a1.finish < a2.finish;
}

// Function to find the maximum number of activities using DP
int activitySelectionDP(vector<Activity>& activities) {
    int n = activities.size();

    // Sort activities by their finish time
    sort(activities.begin(), activities.end(), compareActivity);

    // DP array to store the maximum number of activities up to index i
    vector<int> dp(n, 0);

    // Base case: Only one activity can be selected when there is one activity
    dp[0] = 1;

    // Fill the DP array
    for (int i = 1; i < n; i++) {
        // Include the current activity
        int include_activity = 1;

        // Find the last activity that doesn't conflict with the current activity
        for (int j = i - 1; j >= 0; j--) {
            if (activities[j].finish <= activities[i].start) {
                include_activity = dp[j] + 1;
                break;
            }
        }

        // Store the maximum of including or excluding the current activity
        dp[i] = max(include_activity, dp[i - 1]);
    }

    // The last entry in dp array will have the result
    return dp[n - 1];
}

int main() {
    vector<Activity> activities = {{1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}, {5, 9}};

    cout << "Maximum number of activities that can be selected: " << activitySelectionDP(activities) << endl;

    return 0;
}
