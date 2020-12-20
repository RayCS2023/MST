//
//  MST.cpp
//  MST
//
//  Created by Raymond Chen on 2020-03-26.
//  Copyright © 2020 Raymond Chen. All rights reserved.
//

#include "MST.hpp"
using std::size_t;
using std::vector;
using std::sort;

//constructors
Edge::Edge(int u, int v, double weight) {
    this->u = u;
    this->v = v;
    this->weight = weight;
}

MST::MST() {
    adj_matrix = nullptr;
    matrix_size = 0;
    total_edges = 0;
}

//destructor for deallocating memory
MST::~MST() {
    for(size_t i = 0; i < matrix_size; i++){
        delete[] adj_matrix[i];
    }
    delete[] adj_matrix;
}




//initalize the size of the matrix
void MST::init(int const &matrix_size) {
    //check if m is valid
    if(matrix_size <= 0){
        throw illegal_argument();
    }
    
    //assign matrix size variable
    this->matrix_size = matrix_size;
    
    //creates an array of pointers
    adj_matrix = new double*[matrix_size];
    
    //each pointer points to an array
    for(size_t i = 0; i < matrix_size; i++){
        adj_matrix[i] = new double[matrix_size];
        for(size_t j = 0; j < matrix_size; j++){
            
            //assign initial values;
            adj_matrix[i][j] = 0;
        }
    }
}

void MST::insert(int const &i, int const &j, double const &weight) {
    //checking for valid indexing
    if(i < 0 || j < 0 || i == j)
        throw illegal_argument();
    
    if(i > matrix_size - 1 || j > matrix_size - 1)
        throw illegal_argument();
    
    //check for valid edge weight
    if(weight <= 0.0){
        throw illegal_argument();
    }
    
    bool exist = false;
    //if all checks passed, assign matrix value;
    adj_matrix[i][j] = weight;
    adj_matrix[j][i] = weight;
    
    
    //search if edge already exist, update weight if it does
    for (size_t k = 0; k < total_edges; k++){
        if((edges[k].u == i && edges[k].v == j) ||(edges[k].u == j && edges[k].v == i)){
            edges[k].weight = weight;
            exist = true;
            break;
        }
    }
    
    //add edge to vector if it does not exist
    if(!exist){
        Edge edge(i,j,weight);
        edges.push_back(edge);
        total_edges++;
    }
}

bool MST::del(const int &i, const int &j) { 
    //checking for valid indexing
    if(i < 0 || j < 0 || i == j)
        throw illegal_argument();
    
    if(i > matrix_size - 1 || j > matrix_size - 1)
        throw illegal_argument();
    
    //check if weight is  0, if so, no edge exist
    if(!adj_matrix[i][j]){
        return false;
    }
    
    //if all checks passed, reset weight at index to 0
    adj_matrix[i][j] = 0;
    adj_matrix[j][i] = 0;
    
    //search for the edge and remove if found
    for (size_t k = 0; k < total_edges; k++){
        if((edges[k].u == i && edges[k].v == j) || (edges[k].u == j && edges[k].v == i)){
            edges.erase(edges.begin() + k);
            total_edges--;
            break;
        }
    }
    return true;
}

//return the total number of edges
int MST::edgeCount() const { 
    return total_edges;
}

bool MST::clear() { 
    total_edges = 0;
    
    //loop through matrix
    for(size_t i = 0; i < matrix_size; i++){
        adj_matrix[i] = new double[matrix_size];
        for(size_t j = 0; j < matrix_size; j++){
            
            //assign initial values;
            adj_matrix[i][j] = 0;
        }
    }
    
    return true;
}

int MST::deg_vertex(const int &i) const {
    //checking for valid indexing
    if(i < 0)
        throw illegal_argument();
    
    if(i > matrix_size - 1)
        throw illegal_argument();
    
    int degree = 0;
    
    //find the number of non-zero/non-negative values in row i
    for(size_t j = 0; j < matrix_size; j++){
        //edge exist if the value is greater than 0
        if(adj_matrix[i][j] > 0){
            degree++;
        }
    }
    
    return degree;
}

double MST::mst() {
    //edge count for checking is graph is connected;
    int count = 0;
    
    //min-weight variable
    double min_weight = 0;
    
    DisjointSet ds(matrix_size);
    
    //create a set for each vertex
    for (int i = 0; i < matrix_size; i++){
        ds.MakeSet(i);
    }
    
    //sorts the edges from least to greatest
    sort(edges.begin(), edges.end());
    
    //loop through all edges
    
    for (size_t i = 0; i < edges.size(); i++){
        //check if the vertex belong to the same set
        if(ds.FindSet(edges[i].u) != ds.FindSet(edges[i].v)){
            min_weight += edges[i].weight; //add to weight
            ds.Union(edges[i].u, edges[i].v); // merge the two sets into one
            count++;
        }
    }
    
    //check to see if the graph is not connected
    if(count != matrix_size - 1 ){
        return -1.0;
    }
    
    return min_weight;
    
}
