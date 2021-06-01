#include "Figure.h"
#include "Point.h"

const double PI = 3.14159265;

class Circle: public Figure{
public:
    explicit Circle(Point& centre, double& radius);
    double GetSquare() const override;

private:
    Point centre;
    double radius;
};
