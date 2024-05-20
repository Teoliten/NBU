#include <bits/stdc++.h>

/*
TASK:
Provide an implementation of the breadth-first search algorithm on a graph
represented with adjacency lists data structure. Provide that your implementation
prints out the sate of the graph after each step of the algorithm, and shows how
the color, d and \pi attributes of each vertex are changed. Represent the graph as a C++ class.
Provide an iterative implementation of the function that prints a shortest path.
*/

using namespace std;

class Graph
{
public:
  Graph(int vert);                                            // constructor
  void addEdgeDirected(int vertexA, int vertexB, int weight); // add edge between two vertices with a weight
  void printGraph();                                          // print graph, showing connected vertices
  void BFS(int start);                                        // Breadth-first search given a start vertex

private:
  int vertices;                          // number of verices in graph
  vector<pair<int, int>> *adjacencyList; // list containing all vertices, edges and weight
}; // Class Graph

Graph::Graph(int vertices)
{
  this->vertices = vertices;
  adjacencyList = new vector<pair<int, int>>[vertices];
} // Constructor

void Graph::addEdgeDirected(int vertexA, int vertexB, int weight)
{
  adjacencyList[vertexA].push_back({vertexB, weight});
} // addEdgeDirected

void Graph::printGraph()
{
  cout << vertices;
  for (int i = 0; i < vertices; ++i)
  {
    cout << "\n Vertex " << i << ":";
    for (auto edge : adjacencyList[i])
    {
      cout << " --> (" << edge.first << ", " << edge.second << ")";
    }
    cout << "\n";
  }
} // printGraph

void Graph::BFS(int start)
{
  vector<int> distance(vertices, INT_MAX);
  vector<bool> visited(vertices, false);

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

  distance[start] = 0;
  pq.push({0, start});
  while (!pq.empty())
  {
    // Get the vertex with minimum distance from the priority queue
    int u = pq.top().second;
    pq.pop();

    // Mark the vertex as visited
    visited[u] = true;

    // Traverse all adjacent vertices of u
    for (auto edge : adjacencyList[u])
    {
      int v = edge.first;
      int weight = edge.second;

      // Relax the edge if it improves the distance to v
      if (!visited[v] && distance[u] + weight < distance[v])
      {
        distance[v] = distance[u] + weight;
        pq.push({distance[v], v});
      }
    }
  }

  // Print the shortest distances to each vertex
  for (int i = 0; i < vertices; ++i)
  {
    cout << "Vertex " << i << ": " << distance[i] << endl;
  }
} // BFS

int main()
{
  Graph D(5); // Create a DIRECTED adjacency list with 5 vertices NOT WEIGHTED
  D.addEdgeDirected(0, 1, 5);
  D.addEdgeDirected(1, 2, 3);
  D.addEdgeDirected(1, 3, 6);
  D.addEdgeDirected(1, 4, 2);
  D.addEdgeDirected(2, 3, 7);
  D.addEdgeDirected(2, 1, 1);
  D.addEdgeDirected(3, 4, 4);
  D.addEdgeDirected(4, 2, 9);

  cout << "DIRECTED:\n";
  D.printGraph(); // print
  cout << "BFS starting from vertex 0:\n";
  D.BFS(0);

  return 0;
} // main