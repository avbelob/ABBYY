#include "Figure.h"
#include "Point.h"

class Rectangle: public Figure {
public:
    explicit Rectangle(Point& first_point, Point& second_point, Point& third_point);
    double GetSquare() const override;

private:
    // Прямоугольник однозначно задаётся тремя точками
    Point first_point;
    Point second_point;
    Point third_point;
};

