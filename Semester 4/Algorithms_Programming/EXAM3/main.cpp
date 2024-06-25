#include <bits/stdc++.h>
#include "graph.h"

// Implement the following program using C++ programming language.
// Use separate compilation (define classes in .h and implement them in .cpp).
// Represent a directed graph using adjacency lists.
// Implement the Ford-Fulkerson method. Test the solution.

using namespace std;

int main()
{
    int vertices = 6;
    // cin >> vertices;

    Graph g(vertices);

    g.addEdge(0, 1, 16);
    g.addEdge(0, 2, 13);
    g.addEdge(1, 2, 10);
    g.addEdge(1, 3, 12);
    g.addEdge(2, 1, 4);
    g.addEdge(2, 4, 14);
    g.addEdge(3, 2, 9);
    g.addEdge(3, 5, 20);
    g.addEdge(4, 3, 7);
    g.addEdge(4, 5, 4);

    cout << "The maximum possible flow is " << g.fordFulkerson(0, 5) << endl; // Source is 0 and Sink is 5

    return 0;
} // main