#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Activity {
    int start, finish;
};

// Comparator to sort by start time
bool compareActivity(Activity a1, Activity a2) {
    return a1.start < a2.start;
}

int minLectureHalls(vector<Activity>& activities) {
    if (activities.empty()) return 0;

    // Sort activities by start time
    sort(activities.begin(), activities.end(), compareActivity);

    // Min-heap to track the earliest finishing activity
    priority_queue<int, vector<int>, greater<int>> pq;

    // Assign first activity to the first hall
    pq.push(activities[0].finish);

    for (int i = 1; i < activities.size(); i++) {
        // If the current activity starts after the earliest finishing one, reuse the hall
        if (activities[i].start >= pq.top()) {
            pq.pop();
        }

        // Assign the current activity to a hall
        pq.push(activities[i].finish);
    }

    // The size of the heap is the number of halls required
    return pq.size();
}

int main() {
    vector<Activity> activities = {{0, 5}, {1, 2}, {1, 10}, {2, 3}, {5, 7}, {8, 9}};

    cout << "Minimum number of lecture halls required: " << minLectureHalls(activities) << endl;

    return 0;
}
