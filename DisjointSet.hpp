//
//  DisjointSet.hpp
//  MST
//
//  Created by Raymond Chen on 2020-03-27.
//  Copyright © 2020 Raymond Chen. All rights reserved.
//

#ifndef DisjointSet_hpp
#define DisjointSet_hpp

#include <iostream>
#include <vector>
#include <algorithm>

class Set;

class Node{
private:
    friend class DisjointSet;
    int u; // vertex value
    Set* list;
    Node* next;
public:
    Node();
    Node(int const &u);
    ~Node();
};

class Set{
private:
    friend class DisjointSet;
    int rank;
    Node* tail;
    Node* head;
public:
    Set();
    ~Set();
};


class DisjointSet{
    friend class MST;
public:
    DisjointSet( int const &size );
    ~DisjointSet();
    void MakeSet( int const &u );
    Node* FindSet(int const &u);
    void Union(int const &u, int const &v);
private:
    std::vector<Node*> vertex;
};

#endif /* DisjointSet_hpp */
