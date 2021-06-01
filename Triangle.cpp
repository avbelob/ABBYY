#include "Triangle.h"
#include <cmath>

Triangle::Triangle(Point &first_point, Point &second_point, Point &third_point) : first_point(first_point),
                                                                                  second_point(second_point),
                                                                                  third_point(third_point) {}

double Triangle::GetSquare() const {
    return 0.5 * std::abs((second_point.x - first_point.x) * (third_point.y - first_point.y) -
                          (third_point.x - first_point.x) * (second_point.y - first_point.y));
}