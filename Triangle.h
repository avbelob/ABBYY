#include "Figure.h"
#include "Point.h"

class Triangle: public Figure {
public:
    explicit Triangle(Point& first_point, Point& second_point, Point& third_point);
    double GetSquare() const override;

private:
    Point first_point;
    Point second_point;
    Point third_point;
};

