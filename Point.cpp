//
// Created by IamPu on 31.01.2022.
//

#include "Point.h"

const std::string &Point::getName() const{
    return name;
}

void Point::add(double _x, double _y) {
    x += _x;
    y += _y;
}

double Point::distance(Point &point) const {
    return macro_distance(x,y,point.x,point.y); //macros used
}
