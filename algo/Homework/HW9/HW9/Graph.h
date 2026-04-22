#pragma once
#include <iostream>
#include <stdexcept>

class Graph {
private:
    int numVertices;
    int** matrix;

    void allocateMemory();
    void freeMemory();
    void copyFrom(const Graph&);

public:
    Graph(int);
    Graph(const Graph&);
    Graph& operator=(const Graph&);
    ~Graph();

    void addEdge(int, int, int);
    int* dijkstra(int) const;
    void printMatrix(std::ostream&) const;
    int getNumVertices() const { return numVertices; }
};