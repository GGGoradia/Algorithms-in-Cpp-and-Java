#include <iostream>
using namespace std;

struct Point {
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}
};

bool arePerpendicular(const Point& p1, const Point& p2, const Point& p3, const Point& p4) {
    // Calculate slope components in cross-multiplication form
    int dx1 = p2.x - p1.x;
    int dy1 = p2.y - p1.y;
    int dx2 = p4.x - p3.x;
    int dy2 = p4.y - p3.y;

    // Check for perpendicularity using cross product
    return (dy1 * dy2) == -(dx1 * dx2);
}

int main() {
    Point p1(0, 0), p2(1, 1);
    Point p3(0, 0), p4(-1, 1);

    if (arePerpendicular(p1, p2, p3, p4)) {
        cout << "The line segments are perpendicular." << endl;
    } else {
        cout << "The line segments are not perpendicular." << endl;
    }

    return 0;
}