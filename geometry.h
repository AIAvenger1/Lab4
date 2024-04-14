



#ifndef LAB03V04_GEOMETRY_H
#define LAB03V04_GEOMETRY_H

#include "iostream"

const double EPS = 1E-9;

namespace geometry
{

    struct Point {
        double x;
        double y;
        Point();
        Point(double ,double);
        friend std::istream& operator>>(std::istream & is, Point & a);
        friend std::ostream& operator<<(std::ostream & os, Point & a);
    };
    struct Line
    {
        Point a;
        Point b;
        Line();
        Line(Point, Point);
        //friend std::istream & operator>>(std::istream is, Line p);
    };

    struct Quad {
        Point a; Point b; Point c; Point d;
        Quad();
        Quad(Point, Point, Point, Point);
        //friend std::istream& operator>>(std::istream & is, Quad & A);
    };

    bool read_point(Point & );
    void multiple_read(Point & );
}
#endif //LAB03V04_GEOMETRY_H
