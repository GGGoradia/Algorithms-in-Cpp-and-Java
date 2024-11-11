#include <iostream>
using namespace std;

struct Point {
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}
};

bool areParallel(const Point& p1, const Point& p2, const Point& p3, const Point& p4) {
    // Calculate slopes in cross-multiplication form to avoid division
    int dx1 = p2.x - p1.x;
    int dy1 = p2.y - p1.y;
    int dx2 = p4.x - p3.x;
    int dy2 = p4.y - p3.y;

    // Check for parallelism
    return (dy1 * dx2) == (dy2 * dx1);
}

int main() {
    Point p1(1, 2), p2(3, 4);
    Point p3(2, 3), p4(4, 5);

    if (areParallel(p1, p2, p3, p4)) {
        cout << "The line segments are parallel." << endl;
    } else {
        cout << "The line segments are not parallel." << endl;
    }

    return 0;
}
