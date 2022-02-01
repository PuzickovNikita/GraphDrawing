//
// Created by IamPu on 02.02.2022.
//

#ifndef GRAPHDRAWING_EDGE_H
#define GRAPHDRAWING_EDGE_H

#include "Point.h"

class Edge {
private:
    Point& p1;
    Point& p2;
    double goal_length;
    double cur_length;
public:
    Edge(Point& _p1, Point& _p2, const double& _goal):p1(_p1), p2(_p2), goal_length(_goal){
        cur_length = p1.distance(p2);
    }

    double curLength() const{
        return cur_length;
    }

    double goalLength() const{
        return goal_length;
    }
};


#endif //GRAPHDRAWING_EDGE_H
