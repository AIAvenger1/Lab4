//
// Created by Bohdan Petrov on 27.03.2024.
//
#include <iostream>
#include "quad.h"
#include "ray.h"
#include "geometry.h"
#include "boolgeom.h"

int main()
{
    geometry::Quad quad;
    geometry::Line ray;
    geometry::quad::multiple_read_quad(quad);
    geometry::Ray::multiple_read_ray(ray);
    if(geometry::boolgeom::exercise(quad,ray))
        std::cout << "Yes";
    else std::cout << "NO";
    return 0;
}
