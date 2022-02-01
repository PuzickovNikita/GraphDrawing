//
// Created by IamPu on 31.01.2022.
//
#include <iostream>
#include <iomanip>

#include "Graph.h"


int Graph::pointIndex(const std::string &_name) {
    auto it = vertices.begin();
    for(int i = 0;
    it != vertices.end(); it++, i++){
        if(it->getName() == _name)
            return i;
    }
    return -1;
}

bool Graph::addVertex(const double &_x, const double &_y, const std::string &_name) {

    if(pointIndex(_name) == -1) {
        vertices.emplace_back(_x, _y, _name);

        for(auto &it: edges){
            it.push_back(nullptr);
        }
        edges.emplace_back();
        for(int i = 0; i < edges.size(); i++)
            edges.back().push_back(nullptr);
        return true;
    }
    else
        return false;
}

bool Graph::addEdge(const std::string &V1, const std::string &V2, const double &length) {
    int i, j;
    i = pointIndex(V1);
    j = pointIndex(V2);
    if((i == -1)||(j == -1))
        return false;
    return addEdge(i,j,length);
}

bool Graph::addEdge(const int &i, const int &j, const double &length) {

    unsigned int _size = edges.size();
    if((i > _size)||(j > _size))
        return false;
    Edge* new_edge = new Edge(vertices[i], vertices[j], length);
    edges[i][j] = new_edge;
    edges[j][i] = new_edge;
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
        for(auto & elem: row) {
            if(elem == nullptr)
                os << std::setw(maxlen) << std::right << 0 << ' ';
            else
                os << std::setw(maxlen) << std::right << elem->goalLength() << ' ';
        }
        os << std::endl;
    }
    os << std::endl;
    return os;
}

Graph::~Graph() {

    for(int i = 0; i < edges.size(); i++)
        for(int j = i; j < edges.size(); j++) {
            if(edges[i][j] != edges[j][i])
                std::cerr << "Несимметричная матрица смежности:(" << i << ',' << j << std::endl;
            if(edges[i][j] == nullptr)
                continue;
            if( (i == j) && (edges[i][j] != nullptr))
                std::cerr << "Заполнен диагональный элемент матрицы смежности:(" << i << ',' << j << std::endl;
            delete edges[i][j];
            edges[i][j] = nullptr;
            edges[j][i] = nullptr;
        }
}


