//
// Created by Bohdan Petrov on 27.03.2024.
//

#ifndef LAB04_RAY_H
#define LAB04_RAY_H

#include "geometry.h"

namespace geometry::Ray
{
    bool read_ray(Line & Ray);
    bool multiple_read_ray(Line & Ray);

} // no need for structure due to existence of Line()

#endif //LAB04_RAY_H
