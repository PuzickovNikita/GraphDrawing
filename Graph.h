//
// Created by IamPu on 31.01.2022.
//

#ifndef GRAPHDRAWING_GRAPH_H
#define GRAPHDRAWING_GRAPH_H

#include "Point.h"

#include <vector>

class Graph {
private:
    std::vector<Point> vertices;
    std::vector< std::vector<double> > edges;

public:
    int findPoint(const std::string& _name);

    Graph(){}
    bool addVertex(const double& _x, const double& _y, const std::string& _name);
    bool addEdge(const int& i, const int& j, const double& length);
    bool addEdge(const std::string& V1, const std::string& V2, const double& length);

    friend std::ostream& operator<<(std::ostream& os, const Graph& dt);
};


#endif //GRAPHDRAWING_GRAPH_H
