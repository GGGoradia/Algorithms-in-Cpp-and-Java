#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Define a structure to represent a point
struct Point {
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}
};

// Function to calculate the squared distance between two points
int squaredDistance(const Point& p1, const Point& p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

// Function to calculate the cross product of vectors p0p1 and p0p2
int crossProduct(const Point& p0, const Point& p1, const Point& p2) {
    int dx1 = p1.x - p0.x;
    int dy1 = p1.y - p0.y;
    int dx2 = p2.x - p0.x;
    int dy2 = p2.y - p0.y;
    return dx1 * dy2 - dy1 * dx2;
}

// Custom comparator to sort points based on their polar angle with respect to p0
bool polarAngleComparator(const Point& p1, const Point& p2, const Point& p0) {
    int cp = crossProduct(p0, p1, p2);

    // If the cross product is zero, the points are collinear
    if (cp == 0) {
        // Sort by distance from p0 if collinear
        return squaredDistance(p0, p1) < squaredDistance(p0, p2);
    }
    // Return true if p1 is counterclockwise to p2
    return cp > 0;
}

// Function to sort points based on polar angle with respect to p0
void sortPointsByPolarAngle(vector<Point>& points, const Point& p0) {
    sort(points.begin(), points.end(),
        [&](const Point& p1, const Point& p2) {
            return polarAngleComparator(p1, p2, p0);
        });
}

int main() {
    vector<Point> points = {{2, 3}, {4, 2}, {1, 5}, {3, 6}, {0, 4}};
    Point p0(0, 0);
    sortPointsByPolarAngle(points, p0);
    cout << "Points sorted by polar angle with respect to (" << p0.x << ", " << p0.y << "):\n";
    for (const auto& point : points) {
        cout << "(" << point.x << ", " << point.y << ")\n";
    }

    return 0;
}
