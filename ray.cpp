//
// Created by Bohdan Petrov on 27.03.2024.
//

#include "ray.h"
#include "geometry.h"
#include <iostream>

namespace geometry::Ray{
    bool read_ray(Line & Ray)
    {

        std::cout << "Enter 1 point:" << '\n';
        multiple_read(Ray.a);
        std::cout << "Enter 2 point:" << '\n';
        multiple_read(Ray.b);
        if(Ray.a.x == Ray.b.x && Ray.a.y == Ray.b.y)
        {
            std::cout << "Wrong input, same point. Try again" << '\n';
            return 0;
        }
        return 1;
    }
    bool multiple_read_ray(Line & Ray)
    {
        std::cout << "Enter points for ray" << '\n';
        while(!(read_ray(Ray)));
    }
}