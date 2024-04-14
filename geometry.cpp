//
// Created by Bohdan Petrov on 27.03.2024.
//

#include "geometry.h"


using std::cin;
using std::cout;

namespace geometry
{

    Point::Point()
    : x(), y() {}

    Point::Point(double x, double y)
    : x(x), y(y) {}

    std::istream & operator >> (std::istream& is, Point & a)
    {
        is >> a.x >> a.y;
        return is;
    }

    Line::Line()
    : a(), b() {}

    Line::Line(Point a, Point b)
    : a(a), b(b) {}

    Quad::Quad()
    : a(), b(), c(), d() {}

    Quad::Quad(geometry::Point a, geometry::Point b, geometry::Point c, geometry::Point d)
    : a(a), b(b), c(c), d(d) {}

    bool read_point(Point & p){
        std::cin >> p;
        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(80, '\n');
            std::cout << "Wrong input. Try again." <<  std::endl;
            return 0;
        }
        return 1;
    }

    void multiple_read(Point & p){
        std::cout << "Enter point as x y:" << '\n';
        while(!(read_point(p)));
    }

}
