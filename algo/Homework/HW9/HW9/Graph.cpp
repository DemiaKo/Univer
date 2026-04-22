#include "Graph.h"

void Graph::allocateMemory() {
    matrix = new int* [numVertices];
    for (int i = 0; i < numVertices; ++i) {
        matrix[i] = new int[numVertices];
        for (int j = 0; j < numVertices; ++j) {
            matrix[i][j] = -1;
        }
    }
}

void Graph::freeMemory() {
    for (int i = 0; i < numVertices; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void Graph::copyFrom(const Graph& other) {
    numVertices = other.numVertices;
    allocateMemory();
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            matrix[i][j] = other.matrix[i][j];
        }
    }
}

Graph::Graph(int vertices) {
    if (vertices <= 0) throw std::invalid_argument("Кількість вершин має бути більшою за 0");
    numVertices = vertices;
    allocateMemory();
}

Graph::Graph(const Graph& other) {
    copyFrom(other);
}

Graph& Graph::operator=(const Graph& other) {
    if (this != &other) {
        freeMemory();
        copyFrom(other);
    }
    return *this;
}

Graph::~Graph() {
    freeMemory();
}

void Graph::addEdge(int u, int v, int weight) {
    if (u < 0 || u >= numVertices || v < 0 || v >= numVertices) {
        throw std::out_of_range("Недійсний індекс вершини!");
    }
    if (weight < 0) {
        throw std::invalid_argument("Алгоритм Дейкстри не підтримує від'ємні ваги ребер!");
    }
    matrix[u][v] = weight; 
}

int* Graph::dijkstra(int startVertex) const {
    if (startVertex < 0 || startVertex >= numVertices) {
        throw std::out_of_range("Недійсний індекс стартової вершини!");
    }

    int* distances = new int[numVertices];
    bool* visited = new bool[numVertices];

    for (int i = 0; i < numVertices; ++i) {
        distances[i] = INT_MAX;
        visited[i] = false;
    }

    distances[startVertex] = 0;

    for (int count = 0; count < numVertices - 1; ++count) {
        int minDistance = INT_MAX;
        int u = -1;

        for (int i = 0; i < numVertices; ++i) {
            if (!visited[i] && distances[i] <= minDistance) {
                minDistance = distances[i];
                u = i;
            }
        }

        if (u == -1 || distances[u] == INT_MAX) break;

        visited[u] = true;

        for (int v = 0; v < numVertices; ++v) {
            if (!visited[v] && matrix[u][v] != -1 && distances[u] != INT_MAX &&
                distances[u] + matrix[u][v] < distances[v]) {
                distances[v] = distances[u] + matrix[u][v];
            }
        }
    }

    delete[] visited;
    return distances;
}

void Graph::printMatrix(std::ostream& os) const {
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            if (matrix[i][j] == -1) os << "X\t";
            else os << matrix[i][j] << "\t";
        }
        os << "\n";
    }
}