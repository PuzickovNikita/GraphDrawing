//
// Created by IamPu on 31.01.2022.
//
#include <iostream>
#include <iomanip>

#include "Graph.h"


int Graph::findPoint(const std::string &_name) {
    auto it = vertices.begin();
    for(int i = 0;
    it != vertices.end(); it++, i++){
        if(it->getName() == _name)
            return i;
    }
    return -1;
}

bool Graph::addVertex(const double &_x, const double &_y, const std::string &_name) {

    if(findPoint(_name) == -1) {
        vertices.emplace_back(_x, _y, _name);
        for(auto & it: edges){
            it.push_back(0.0);
        }
        edges.emplace_back();
        const int _last = vertices.size() - 1;
        for(int i = 0; i < _last; i++){
            edges.back().push_back(edges[i][_last]);
        }
        edges.back().push_back(-1);
        return true;
    }
    else
        return false;
}

bool Graph::addEdge(const std::string &V1, const std::string &V2, const double &length) {
    int i, j;
    i = findPoint(V1);
    j = findPoint(V2);
    if((i == -1)||(j == -1))
        return false;
    return addEdge(i,j,length);
}

bool Graph::addEdge(const int &i, const int &j, const double &length) {
    if((i > edges.size()) || (j > edges.size()) )
        return false;
    edges[i][j] = length;
    edges[j][i] = length;
}

std::ostream &operator<<(std::ostream &os, const Graph &obj) {
    int maxlen_name = 1;
    int maxlen = 4;
    os << std::setw(maxlen_name) << std::right << ' ';
    for(auto & it: obj.vertices){
        os << std::setw(maxlen) << std::right << it.getName() << ' ';
    }
    os << std::endl;
    auto it = obj.vertices.begin();
    for(auto & row: obj.edges){
        os << std::setw(maxlen_name) << std::right << it->getName();
        it++;
        for(auto & elem: row)
            os << std::setw(maxlen) << std::right << elem << ' ';
        os << std::endl;
        }
    os << std::endl;

    return os;
}


