#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
    double x, y;
    bool operator<(const Point &p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
};

double cross(const Point &p1, const Point &p2, const Point &p3) {
    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

vector<Point> mergeHulls(const vector<Point> &leftHull, const vector<Point> &rightHull) {
    int n1 = leftHull.size(), n2 = rightHull.size();
    int i = 0, j = 0;
    for (int k = 1; k < n1; k++)
        if (leftHull[k].x > leftHull[i].x) i = k;
    for (int k = 1; k < n2; k++)
        if (rightHull[k].x < rightHull[j].x) j = k;

    int upper_i = i, upper_j = j;
    bool done = false;
    while (!done) {
        done = true;
        while (cross(rightHull[upper_j], leftHull[upper_i], leftHull[(upper_i + 1) % n1]) > 0)
            upper_i = (upper_i + 1) % n1;
        while (cross(leftHull[upper_i], rightHull[upper_j], rightHull[(n2 + upper_j - 1) % n2]) < 0)
            upper_j = (n2 + upper_j - 1) % n2;
    }

    int lower_i = i, lower_j = j;
    done = false;
    while (!done) {
        done = true;
        while (cross(leftHull[lower_i], rightHull[lower_j], rightHull[(lower_j + 1) % n2]) > 0)
            lower_j = (lower_j + 1) % n2;
        while (cross(rightHull[lower_j], leftHull[lower_i], leftHull[(n1 + lower_i - 1) % n1]) < 0)
            lower_i = (n1 + lower_i - 1) % n1;
    }

    vector<Point> mergedHull;
    int idx = upper_i;
    mergedHull.push_back(leftHull[idx]);
    while (idx != lower_i) {
        idx = (idx + 1) % n1;
        mergedHull.push_back(leftHull[idx]);
    }

    idx = lower_j;
    mergedHull.push_back(rightHull[idx]);
    while (idx != upper_j) {
        idx = (idx + 1) % n2;
        mergedHull.push_back(rightHull[idx]);
    }
    return mergedHull;
}

vector<Point> convexHullDC(vector<Point> &points) {
    if (points.size() <= 3) {
        sort(points.begin(), points.end());
        return points;
    }

    int mid = points.size() / 2;
    vector<Point> left(points.begin(), points.begin() + mid);
    vector<Point> right(points.begin() + mid, points.end());

    vector<Point> leftHull = convexHullDC(left);
    vector<Point> rightHull = convexHullDC(right);

    return mergeHulls(leftHull, rightHull);
}

int main() {
    int n;
    cout << "Enter the number of points: ";
    cin >> n;

    if (n < 3) {
        cout << "Convex Hull requires at least 3 points.\n";
        return 0;
    }

    vector<Point> points(n);
    cout << "Enter the points (x y):\n";
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    sort(points.begin(), points.end());
    vector<Point> hull = convexHullDC(points);

    cout << "Points in the Convex Hull:\n";
    for (const auto &p : hull) {
        cout << "(" << p.x << ", " << p.y << ")\n";
    }
    return 0;
}
