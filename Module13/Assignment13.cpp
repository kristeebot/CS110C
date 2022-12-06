// CS110C
// KristinaHelwing
// ProfMaxLuttrell
// 120522
// This program uses Dijkstra’s algorithm to determine the cheapest flights from SFO to other cities for "CS Airlines"

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include "Matrix.h"
#include "Heap.h"
using namespace std;

// For this assignment, you will implement Dijkstra’s algorithm
// in order to determine the cheapest flights from San Francisco to other cities for a fictitious airline, CS Airlines.
// Design and implement a C++ class to represent this graph using an adjacency matrix.
// In addition to storing the adjacency matrix, your class should include a method which uses Dijkstra’s algorithm in order
// to compute and print out the cheapest cost from San Francisco (vertex 0) to each other city.
// It may help you debug to print out the weight array, v, and vertex set for each iteration of the algorithm.
// SFO || 0
// LAX || 1
// LAS || 2
// PHX || 3
// DEN || 4
// JFK || 5

// Consider the following map of available flights on CS Airlines.
// Each vertex has a name and an index, e.g. SFO has index 0, LAX has vertex 1, etc.
// Each edge has a weight which is the cost of a ticket between the two cities.

// Design and implement a C++ class to represent this graph using an adjacency matrix.
// In addition to storing the adjacency matrix, your class should include a method which uses Dijkstra’s algorithm in order
// to compute and print out the cheapest cost from San Francisco (vertex 0) to each other city.
// It may help you debug to print out the weight array, v, and vertex set for each iteration of the algorithm.


int main()
{
    // priority_queue<int, std::vector<int>, comparator> h;
    // h.push(1000);
    // h.push(19);
    // h.push(1000);
    // h.push(10);
    // h.push(5000);
    // h.push(4000);
    // h.push(10000);
    // h.push(200);
    // while (!h.empty())
    // {
    //     cout << h.top() << endl;
    //     h.pop();
    // }
    // while (!h.isEmpty()) {
    //     int val = h.peekTop();
    //     if (val > 10000) {
    //         cout << "INF" << endl;
    //     } else {
    //         cout << val << endl;
    //     }
    //     h.remove();
    // }
    Matrix m(6);
    int currentRow = 0;
    int currentColumn = 0;
    m.setItem(currentRow, currentColumn++, 0);
    m.setItem(currentRow, currentColumn++, 120);
    m.setItem(currentRow, currentColumn++, 150);
    m.setItem(currentRow, currentColumn++, 500);
    currentColumn = 0;
    currentRow++;

    m.setItem(currentRow, currentColumn++, 120);
    m.setItem(currentRow, currentColumn++, 0);
    m.setItem(currentRow, currentColumn++, 75);
    m.setItem(currentRow, currentColumn++, 350);
    currentRow++;
    currentColumn = 0;

    m.setItem(currentRow, currentColumn++, 150);
    currentColumn++;
    m.setItem(currentRow, currentColumn++, 0);
    currentColumn++;
    m.setItem(currentRow, currentColumn, 250);
    currentColumn++;
    currentColumn = 0;
    currentRow++;

    currentColumn++;
    m.setItem(currentRow, currentColumn++, 75);
    currentColumn++;
    m.setItem(currentRow, currentColumn, 0);
    m.setItem(currentRow, currentColumn, 150);
    currentColumn++;
    currentColumn = 0;
    currentRow++;

    currentColumn++;
    currentColumn++;
    m.setItem(currentRow, currentColumn++, 250);
    m.setItem(currentRow, currentColumn, 150);
    m.setItem(currentRow, currentColumn, 0);
    currentColumn++;
    currentColumn = 0;
    currentRow++;

    m.setItem(currentRow, currentColumn++, 500);
    m.setItem(currentRow, currentColumn++, 350);
    currentColumn++;
    currentColumn++;
    currentColumn++;
    m.setItem(currentRow, currentColumn, 0);
    currentColumn = 0;
    currentRow++;

    m.printShortestPath(0);

    return 0;
}