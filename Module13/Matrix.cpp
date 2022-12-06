
#include <vector>
#include <iostream>
#include "Matrix.h"
#include "Heap.h"


// // Step 1: Initialize
// Create a set vertexSet that contains only vertex 0 (origin)
// n = number of vertices in theGraph
// for (v = 0 through n-1)
// weight[v] = matrix[0][v]
// // Steps 2-n
// // For each v not in vertexSet, weight[v] contains smallest
// // weight of all paths from 0 to v that pass through only
// // vertices in vertexSet before reaching v
// // For each v in vertexSet, weight[v] is the smallest weight
// // of all paths from 0 to v (including outside vertexSet)
// for (step = 2 through n)
// Find smallest weight[v] such that v is not in vertexSet
// add v to vertexSet
// // Check weight[u] for all u not in vertexSet
// for (all vertices u not in vertexSet)
// if (weight[u] > weight[v] + matrix[v][u])

void Matrix::printShortestPath(int startingVertex)
{ 
    MatrixRow vertex = adjacencyMatrix[startingVertex];
    vector <int> vertexSet;
    vertexSet.push_back(startingVertex);
    Heap <int> priorityQueue;
    for (int i=0; i<vertex.size(); i++)
    {
        int value = vertex[i];
        if (value < inf) {
            priorityQueue.add(value);
        }
    }
    while (!priorityQueue.isEmpty()) {
        cout << priorityQueue.peekTop() << endl;
        priorityQueue.remove();
    }
    cout << "TO DO" << endl;
}
