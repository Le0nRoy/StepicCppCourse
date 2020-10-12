//
// Created by lap on 10/12/20.
//

#ifndef STEPICCPPCOURSE_POINT_H
#define STEPICCPPCOURSE_POINT_H
namespace stepic {
struct Point {
    constexpr Point(double x, double y)
            :
            x(x), y(y) {}

    double x = 0;
    double y = 0;
};

constexpr Point operator+(const Point &point1, const Point &point2) {
    return Point(point1.x + point2.x, point1.y + point2.y);
}

constexpr Point operator-(const Point &point1, const Point &point2) {
    return Point(point1.x - point2.x, point1.y - point2.y);
}

constexpr double operator*(const Point &point1, const Point &point2) {
    return (point1.x * point2.x + point1.y * point2.y);
}
}
#endif //STEPICCPPCOURSE_POINT_H
