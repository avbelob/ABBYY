#include <iostream>
#include <memory>
#include "Figure.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"

std::unique_ptr<Circle> GetCirclePtr() {
    std::cout << "Замечательно. Осталось ввести координаты центра и радиус. " << std::endl;
    Point centre;
    double radius;
    std::cout << "Введите координаты центра: " << std::endl;
    std::cin >> centre.x >> centre.y;
    std::cout << "Введите радиус: " << std::endl;
    std::cin >> radius;
    return std::make_unique<Circle>(centre, radius);
}

std::unique_ptr<Triangle> GetTrianglePtr() {
    std::cout << "Замечательно. Осталось ввести координаты трёх точек. " << std::endl;
    Point first_point;
    Point second_point;
    Point third_point;

    std::cout << "Введите координаты первой точки: " << std::endl;
    std::cin >> first_point.x >> first_point.y;

    std::cout << "Введите координаты второй точки: " << std::endl;
    std::cin >> second_point.x >> second_point.y;

    std::cout << "Введите координаты третьей точки: " << std::endl;
    std::cin >> third_point.x >> third_point.y;

    return std::make_unique<Triangle>(first_point, second_point, third_point);
}

std::unique_ptr<Rectangle> GetRectanglePtr() {
    std::cout << "Замечательно. Осталось ввести координаты трёх точек (они однозначно определят прямоугольник). "
              << std::endl;
    Point first_point;
    Point second_point;
    Point third_point;

    std::cout << "Введите координаты первой точки: " << std::endl;
    std::cin >> first_point.x >> first_point.y;

    std::cout << "Введите координаты второй точки: " << std::endl;
    std::cin >> second_point.x >> second_point.y;

    std::cout << "Введите координаты третьей точки: " << std::endl;
    std::cin >> third_point.x >> third_point.y;

    return std::make_unique<Rectangle>(first_point, second_point, third_point);
}


std::unique_ptr<Figure> GetFigurePtr() {
    std::string figure_type;
    std::cout << "Введите тип объекта (круг/треугольник/прямоугольник): " << std::endl;
    std::cin >> figure_type;

    std::unique_ptr<Rectangle> figure_ptr;

    if (figure_type == "круг") {
        return GetCirclePtr();
    }

    if (figure_type == "треугольник") {
        return GetTrianglePtr();
    }

    if (figure_type == "прямоугольник") {
        return GetRectanglePtr();
    }

    throw std::runtime_error("Не знаю таких фигур :c");
}

int main() {
    std::unique_ptr<Figure> figure_ptr = GetFigurePtr();
    std::cout << "Площадь фигуры: " << figure_ptr->GetSquare();
    return 0;
}
