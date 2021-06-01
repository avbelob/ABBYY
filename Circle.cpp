#include "Circle.h"

Circle::Circle(Point &centre, double &radius) : centre(centre), radius(radius) {}

double Circle::GetSquare() const {
    return radius * radius * PI;
}
