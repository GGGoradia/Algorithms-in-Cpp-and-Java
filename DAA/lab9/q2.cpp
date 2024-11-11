#include <iostream>
using namespace std;

struct Point {
    double x, y;
};

// Function to calculate the cross product
double crossProduct(Point p1, Point p2, Point q) {
    return (p2.x - p1.x) * (q.y - p1.y) - (p2.y - p1.y) * (q.x - p1.x);
}

int main() {
    Point p1, p2, q;

    cout << "Enter the coordinates of P1 (x1 y1): ";
    cin >> p1.x >> p1.y;
    cout << "Enter the coordinates of P2 (x2 y2): ";
    cin >> p2.x >> p2.y;
    cout << "Enter the coordinates of point q (xq yq): ";
    cin >> q.x >> q.y;

    double result = crossProduct(p1, p2, q);

    if (result > 0) {
        cout << "Point q is counterclockwise to the line segment P1P2.\n";
    } else if (result < 0) {
        cout << "Point q is clockwise to the line segment P1P2.\n";
    } else {
        cout << "Point q is collinear with the line segment P1P2.\n";
    }

    return 0;
}
