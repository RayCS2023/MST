//
//  MST.hpp
//  MST
//
//  Created by Raymond Chen on 2020-03-26.
//  Copyright © 2020 Raymond Chen. All rights reserved.
//

#ifndef MST_hpp
#define MST_hpp

#include "DisjointSet.hpp"

struct Edge{
    int u;
    int v;
    double weight;
    Edge(int u,int v,double weight);
    bool operator < (const Edge &other) const { return weight < other.weight;}
};

class MST{
public:
    void init(int const &matrix_size);
    void insert(int const &i, int const &j, double const &weight);
    bool del(int const &i, int const &j);
    int edgeCount() const;
    bool clear();
    int deg_vertex(int const &i) const;
    double mst();
    MST();
    ~MST();
private:
    double **adj_matrix;
    int matrix_size;
    int total_edges;
    std::vector<Edge> edges;
    
    
    
};

//"exception" class
class illegal_argument{};




#endif /* MST_hpp */
