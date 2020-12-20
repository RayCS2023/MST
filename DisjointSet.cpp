//
//  DisjointSet.cpp
//  MST
//
//  Created by Raymond Chen on 2020-03-27.
//  Copyright © 2020 Raymond Chen. All rights reserved.
//

#include "DisjointSet.hpp"

//constructors/destructors of Node class
Node::Node() {
    next = nullptr;
    list = nullptr;
}

Node::Node(const int &u) {
    this->u = u;
    next = nullptr;
    list = nullptr;
}

Node::~Node() {
    next = nullptr;
    list = nullptr;
}

//constructors/destructors of Set class
Set::Set() {
    head = nullptr;
    tail = nullptr;
}

Set::~Set() {
    head = nullptr;
    tail = nullptr;
}


void DisjointSet::MakeSet( int const &u) {
    
    //allocate a linked list
    Set *set = new Set();
    
    //allocate a node
    Node *node = new Node(u);
    
    //assign the head and values of the linked list and its rank
    set->head = node;
    set->tail = node;
    set->rank = 0;
    
    //assign node to the set that it belongs in
    node->list = set;
    
    //put vertex into the node vector
    vertex[u] = node;


}

DisjointSet::~DisjointSet() {
    if(vertex.size() != 0){
    
        std::vector<int> unconnect_sets;
        std::vector<bool> free;
        
        //find all the connected/unconnedt sets in the MST and append to vector
        for (int i = 0; i < vertex.size(); i++){
            unconnect_sets.push_back(vertex[i]->list->head->u);
            free.push_back(false);
        }
        
        //check if the memory for that set has been deallated or not, if not, deallocate it
        for (int i = 0; i < unconnect_sets.size(); i++){
            if(free[unconnect_sets[i]] == false){
                free[unconnect_sets[i]] = true;
                delete vertex[unconnect_sets[i]]->list;
            }
        }
        
        //delete memory allocate for each node
        for (int i = 0; i < vertex.size(); i++){
            delete vertex[i];
        }
    }

}

//Constructor of Disjointed Sets
DisjointSet::DisjointSet(const int &size) {
    //create instance of set class
    Node *node = nullptr;

    //initialize the total number to sets
    for (int i = 0; i < size; i++){
        vertex.push_back(node);
    }
}

//returns the head pointer of each linke list
Node* DisjointSet::FindSet(const int &u) {
    return vertex[u]->list->head;
}

void DisjointSet::Union(const int &u, const int &v) {
    
    //traverse v if rank of u is higher than rank of v
    if(vertex[u]->list->rank > vertex[v]->list->rank){
        
        //variable to store the head of the linked list being traversed
        Node *tmp = vertex[v]->list->head;
        
        //merge the link list and assign new tail
        vertex[u]->list->tail->next = tmp;
        vertex[u]->list->tail = vertex[v]->list->tail;
        
        //deallocate memory of the linked list in V since it will be overwritten
        delete vertex[v]->list;
        
        //loop to update the the linke list of nodes in v
        while(tmp!=nullptr){
            tmp->list = vertex[u]->list;
            tmp = tmp->next;
        }
        
        
        
        //update rank
        vertex[v]->list->rank = vertex[u]->list->rank;
    }
    //traverse u if rank of v is higher or equal to the rank of v
    else{
        //variable to store the head of the linked list being traversed
        Node* tmp = vertex[u]->list->head;
        
        //merge the link list and assign new tail
        vertex[v]->list->tail->next = tmp;
        vertex[v]->list->tail = vertex[u]->list->tail;
        
        //deallocate memory of the linked list in U since it will be overwritten
        delete vertex[u]->list;
        
        //loop to update the the linke list of nodes in u
        while(tmp!=nullptr){
            tmp->list = vertex[v]->list;
            tmp = tmp->next;
        }
        
        
        
        //update rank
        if(vertex[u]->list->rank < vertex[v]->list->rank)
            vertex[u]->list->rank = vertex[v]->list->rank;
        else{
            vertex[u]->list->rank++;
            vertex[v]->list->rank++;
        }
    }
}






