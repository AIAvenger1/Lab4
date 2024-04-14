//
// Created by Bohdan Petrov on 27.03.2024.
//

#include "quad.h"

namespace geometry::quad
{

//std::istream & operator>>(std::istream &is, geometry::quad::Quad &A) {
//    is >> A.a >> A.b >> A.c >> A.d;
//    return is;
//}

bool read_quad(Quad & A)
{
    std::cout << "Enter 1 point:" << '\n';
    multiple_read(A.a);
    std::cout << "Enter 2 point:" << '\n';
    multiple_read(A.b);
    std::cout << "Enter 3 point:" << '\n';
    multiple_read(A.c);
    std::cout << "Enter 4 point:" << '\n';
    multiple_read(A.d);
    Line semgAB(A.a, A.b); Line semgBC(A.b, A.c); Line semgCD(A.c, A.d); Line semgDA(A.d, A.a);

    if(geometry::boolgeom::point_on_line(semgAB,A.c)
    || geometry::boolgeom::point_on_line(semgAB,A.d)
    || geometry::boolgeom::point_on_line(semgBC,A.a)
    || geometry::boolgeom::point_on_line(semgBC,A.d)
    || geometry::boolgeom::point_on_line(semgCD,A.a)
    || geometry::boolgeom::point_on_line(semgCD,A.b)
    || geometry::boolgeom::point_on_line(semgDA,A.b)
    || geometry::boolgeom::point_on_line(semgDA,A.c))
    {
        std::cout << "Wrong input. It's not a quad. Try again" << '\n';
        return 0;
    }
    std::cout << geometry::boolgeom::intersect_segment_segment(semgAB,semgCD)
    << " " << geometry::boolgeom::intersect_segment_segment(semgBC,semgDA) << '\n';
    if(geometry::boolgeom::intersect_segment_segment(semgAB,semgCD)
    || geometry::boolgeom::intersect_segment_segment(semgBC,semgDA))
    {
        std::cout << "Wrong input. It's not a quad. Try again" << '\n';
        return 0;
    }
    return 1;
}

bool multiple_read_quad(Quad & A)
{
    std::cout << "Enter points for quad" << '\n';
    while(!read_quad(A)) ;
}

}
