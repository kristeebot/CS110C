
#include <vector>
#include <iostream>
#include <queue>
#include "Matrix.h"
#include "Heap.h"

using namespace std;

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

struct VertexItem
{
    int index;
    int weight;
};
bool operator<(const VertexItem &v1, const VertexItem &v2)
{
    return v1.weight < v2.weight;
}
bool operator>(const VertexItem &v1, const VertexItem &v2)
{
    return v1.weight > v2.weight;
}
bool operator<=(const VertexItem &v1, const VertexItem &v2)
{
    return v1.weight <= v2.weight;
}

struct comparator
{
    bool operator()(VertexItem i, VertexItem j)
    {
        return i > j;
    }
};

void Matrix::printShortestPath(int startingVertex)
{
    MatrixRow vertex = adjacencyMatrix[startingVertex];
    vector<int> vertexSet; // Vertices we've visted
    vertexSet.push_back(startingVertex);

    vector<int> outputWeights;
    vector<int> previousVertices;

    // These hold the output values
    outputWeights.resize(adjacencyMatrix.size(), inf);
    outputWeights[startingVertex] = 0;

    previousVertices.resize(adjacencyMatrix.size(), -1);

    // Using the STL priority_queue after a lot of frustration
    // and googling and trying to make my old max Heap class into
    // a min heap. I suppose I could also use the old heap,
    // push everything into a stack and pop everything off
    // to reverse it, but if I have time I'll fix my own
    // heap to function as a min heap.
    std::priority_queue<VertexItem, std::vector<VertexItem>, comparator> priorityQueue;
    for (int i = 0; i < vertex.size(); i++)
    {
        if (i == startingVertex)
        {
            // Don't revisit the starting vertex
            continue;
        }
        int value = vertex[i];
        if (value < inf)
        {
            // only consider reachable nodes
            VertexItem vi;
            vi.index = i;
            vi.weight = value;
            priorityQueue.push(vi);
        }
    }

    int lastWeight = 0;
    while (!priorityQueue.empty())
    {
        VertexItem val = priorityQueue.top();
        priorityQueue.pop();
        if (std::find(vertexSet.begin(), vertexSet.end(), val.index) != vertexSet.end())
        {
            // already visited this node
            continue;
        }
        MatrixRow nextRow = adjacencyMatrix[val.index];
        for (int i = 0; i < nextRow.size(); i++)
        {
            int matrixWeight = nextRow[i];
            int summedWeight = lastWeight + matrixWeight;

            if (summedWeight < outputWeights[i])
            {
                outputWeights[i] = summedWeight;
                previousVertices[i] = val.index;
                VertexItem adjItem;
                adjItem.index = i;
                adjItem.weight = matrixWeight;
                priorityQueue.push(adjItem);
            }
        }
    }

    for (std::vector<int>::const_iterator i = outputWeights.begin(); i != outputWeights.end(); ++i)
    {
        cout << *i << ", ";
    }
    cout << endl;
    for (std::vector<int>::const_iterator i = previousVertices.begin(); i != previousVertices.end(); ++i)
    {
        cout << *i << ", ";
    }
    cout << endl;
}
