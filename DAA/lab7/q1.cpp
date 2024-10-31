#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Activity {
    int start, finish;
};

bool compareActivity(Activity a1, Activity a2) {
    return a1.start > a2.start;
}

void activitySelection(vector<Activity>& activities) {
    sort(activities.begin(), activities.end(), compareActivity);

    cout << "Selected activities (start, finish):" << endl;

    int n = activities.size();
    Activity lastSelected = activities[0];
    cout << "(" << lastSelected.start << ", " << lastSelected.finish << ")" << endl;

    for (int i = 1; i < n; i++) {
        if (activities[i].finish <= lastSelected.start) {
            lastSelected = activities[i];
            cout << "(" << lastSelected.start << ", " << lastSelected.finish << ")" << endl;
        }
    }
}

int main() {
    vector<Activity> activities = {{5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}};

    activitySelection(activities);

    return 0;
}
