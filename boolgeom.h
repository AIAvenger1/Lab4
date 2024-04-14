//
// Created by Bohdan Petrov on 13.04.2024.
//

#ifndef LAB4_BOOLGEOM_H
#define LAB4_BOOLGEOM_H
#include "geometry.h"
#include "iostream"
#include "quad.h"

namespace geometry::boolgeom
{

    bool point_on_line(Line, Point);

    bool point_between(double a, double b, double value); //whether values is in (a,b) є R^(1) (don't confuse with Point(x,y), it's just x1,x2 or y1,y2, since work for both)

    bool point_on_ray(double a, double b, double point); //whether values is in (a,+\inf) or (-\inf,a) є R^(1) (-//-)

    bool projection_intersect(double Ray1, double Ray2, double Seg1, double Seg2); // checks if (a,+\inf) and (c,d) is intersecting

    bool intersect(double a, double b, double c, double d); // checks if (a,b) and (c,d) is intersecting

    bool intersect_segment_ray(Line Ray, Line Segment); // obvious

    bool intersect_segment_segment(Line Segment1, Line Segment2); // -//-

    bool exercise(geometry::Quad quad, Line Ray); // checks whether ray intersects quad
}

#endif //LAB4_BOOLGEOM_H Functions that checks whether something is true or not about geometry
