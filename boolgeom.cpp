//
// Created by Bohdan Petrov on 13.04.2024.
//

#include "boolgeom.h"


namespace geometry::boolgeom
{

    bool point_on_line(Line ab, Point c)
    {
        double A = (ab.a.y-ab.b.y), B = (ab.b.x - ab.a.x), C = -ab.a.y*B - ab.a.x*A;
        return !bool(A*c.x + B*c.y + C);
    }

    bool point_between(double a, double b, double value)
    {
        return std::min(a,b) <= value + EPS && value <= std::max(a,b) + EPS;
    }

    bool point_on_ray(double a, double b, double value)
    {
        if(b>a) return (value + EPS >= a);
        if(b<a) return (value +EPS <= a);
    }

    bool projection_intersect(double Ray1, double Ray2, double Seg1, double Seg2){
        if(Ray1 < Ray2) return Ray1 < std::max(Seg2,Seg1);
        else if(Ray1 > Ray2) return std::min(Seg1,Seg2) < Ray1;
    }

    bool intersect(double a, double b, double c, double d)
    {
        if(a > b) std::swap(a,b);
        if(c > d) std::swap(c,d);
        return std::max(a,c) <= std::min(b,d);
    }

    double det(double a, double b, double c, double d)
    {
        return a*d - b*c;
    }
    
    bool intersect_segment_ray(Line Ray, Line Segment)
    {
        double A1 = (Ray.a.y-Ray.b.y), B1 = (Ray.b.x-Ray.a.x), C1 = -Ray.a.y*B1 - Ray.a.x*A1;
        double A2 = (Segment.a.y-Segment.b.y), B2 = (Segment.b.x - Segment.a.x), C2 = -Segment.a.y*B2 - Segment.a.x*A2;
        double denom = det(A1,B1,A2,B2);
        if(denom != 0)
        {
            double x = - det(C1, B1, C2, B2)/ denom;
            double y = - det(A1, C1, A2, C2)/ denom;
            return point_between(Segment.a.x,Segment.b.x,x) && point_between(Segment.a.y,Segment.b.y,y) && point_on_ray(Ray.a.x,Ray.b.x,x) && point_on_ray(Ray.a.y,Ray.b.y,y);
        }
        else
            return det(A1, C1, A2, C2) == 0 && det(A1, C1, A2, C2) == 0 && intersect(Ray.a.x,Ray.b.x,Segment.a.x,Segment.b.x) && projection_intersect(Ray.a.y,Ray.b.y,Segment.a.y,Segment.b.y);
    }

    bool intersect_segment_segment(Line Segment1, Line Segment2)
    {
        double A1 = (Segment1.a.y-Segment1.b.y), B1 = (Segment1.b.x-Segment1.a.x), C1 = -Segment1.a.y*B1 - Segment1.a.x*A1;
        double A2 = (Segment2.a.y-Segment2.b.y), B2 = (Segment2.b.x - Segment2.a.x), C2 = -Segment2.a.y*B2 - Segment2.a.x*A2;
        double denom = det(A1,B1,A2,B2);
        if(denom != 0)
        {
            double x = - det(C1, B1, C2, B2)/ denom;
            double y = - det(A1, C1, A2, C2)/ denom;
            return point_between(Segment1.a.x,Segment1.b.x,x) && point_between(Segment1.a.y,Segment1.b.y,y) && point_between(Segment2.a.y,Segment2.b.y,y) && point_between(Segment2.a.x,Segment2.b.x,x);
        }
        else
            return det(A1, C1, A2, C2) == 0 && det(A1, C1, A2, C2) == 0 && intersect(Segment1.a.x,Segment1.b.x,Segment2.a.x,Segment2.b.x) && intersect(Segment1.a.y,Segment1.b.y,Segment2.a.y,Segment2.b.y);
    }

    bool exercise(geometry::Quad A, Line Ray)
    {
        Line semgAB(A.a, A.b); Line semgBC(A.b, A.c); Line semgCD(A.c, A.d); Line semgDA(A.d, A.a);

        if(intersect_segment_ray(Ray,semgAB )
        || intersect_segment_ray(Ray,semgBC )
        || intersect_segment_ray(Ray,semgCD )
        || intersect_segment_ray(Ray,semgDA )
        ) return 1;

        else return 0;
    }

}