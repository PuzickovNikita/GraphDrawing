//
// Created by IamPu on 31.01.2022.
//

#ifndef GRAPHDRAWING_POINT_H
#define GRAPHDRAWING_POINT_H

#define macro_distance(ax,ay,bx,by) sqrt((bx-ax)*(bx-ax)+(by-ay)*(by-ay))

#include <string>
#include <utility>

class Point {
private:
    double x, y;
    std::string name;
public:
    Point(const double &_x, const double &_y, std::string _name):x(_x), y(_y), name(std::move(_name)){}

    void add(double _x, double _y);

    const std::string& getName() const;

    double distance(Point& point) const;
};


#endif //GRAPHDRAWING_POINT_H
