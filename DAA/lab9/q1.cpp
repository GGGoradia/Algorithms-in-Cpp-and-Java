#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Point {
    double x, y;
};

vector<Point> generatePointsOnLine(double x1, double y1, double x2, double y2, int n) {
    vector<Point> points;
    double stepX = (x2 - x1) / (n - 1);
    double stepY = (y2 - y1) / (n - 1);

    for (int i = 0; i < n; i++) {
        double x = x1 + i * stepX;
        double y = y1 + i * stepY;
        points.push_back({x, y});
    }
    return points;
}

int main() {
    double x1, y1, x2, y2;
    int n;

    cout << "Enter the coordinates of P1 (x1 y1): ";
    cin >> x1 >> y1;
    cout << "Enter the coordinates of P2 (x2 y2): ";
    cin >> x2 >> y2;
    cout << "Enter the number of points to generate (n): ";
    cin >> n;

    if (n < 2) {
        cout << "At least 2 points are required.\n";
        return 0;
    }

    vector<Point> points = generatePointsOnLine(x1, y1, x2, y2, n);

    cout << "Generated points on the line segment:\n";
    cout << fixed << setprecision(2);
    for (const auto &p : points) {
        cout << "(" << p.x << ", " << p.y << ")\n";
    }

    return 0;
}
