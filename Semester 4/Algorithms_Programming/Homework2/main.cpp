#include <bits/stdc++.h>

using namespace std;

class Graph
{
public:
  Graph(int vert);                                    // constructor
  void addEdge(int vertexA, int vertexB, int weight); // add edge between two vertices with a weight
  void printGraph();                                  // print graph, showing connected vertices
  void BFS(int start);                                // Breadth-first search given a start vertex

private:
  int vertices;                          // number of verices in graph
  vector<pair<int, int>> *adjacencyList; // list containing all vertices, edges and weight
  vector<int> state;                     // state of each vertex: 1-unvisited, 2-seen, 3-visited
}; // Class Graph

Graph::Graph(int vertices)
{
  this->vertices = vertices;
  adjacencyList = new vector<pair<int, int>>[vertices];
  state.resize(vertices, 1); // initialize all vertices as unvisited
} // Constructor

void Graph::addEdge(int vertexA, int vertexB, int weight)
{
  adjacencyList[vertexA].push_back({vertexB, weight});
} // addEdge

void Graph::printGraph()
{
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

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

  distance[start] = 0;
  pq.push({0, start});
  while (!pq.empty())
  {
    // Get the vertex with minimum distance from the priority queue
    int u = pq.top().second;
    pq.pop();

    // Mark the vertex as visited
    state[u] = 3;

    // Print the state of each vertex
    for (int i = 0; i < vertices; ++i)
    {
      cout << "Vertex " << i << ": State: " << state[i] << ", Distance: " << (distance[i] == INT_MAX ? "not reached" : to_string(distance[i])) << endl;
    }
    cout << endl;

    // Traverse all adjacent vertices of u
    for (auto edge : adjacencyList[u])
    {
      int v = edge.first;
      int weight = edge.second;

      // Relax the edge if it improves the distance to v
      if (state[v] == 1) // unvisited vertex
      {
        state[v] = 2; // seen but not visited
        distance[v] = distance[u] + weight;
        pq.push({distance[v], v});
      }
    }
  }

} // BFS

int main()
{
  Graph G(5); 
  G.addEdge(0, 1, 5); // vertex 0 connected to vertex 1, with weight 5
  G.addEdge(1, 2, 3);
  G.addEdge(1, 3, 6);
  G.addEdge(2, 3, 7);
  G.addEdge(2, 1, 1);
  G.addEdge(3, 4, 4);
  G.addEdge(3, 4, 2);
  G.addEdge(4, 2, 9);

  G.printGraph();

  cout << "\nBFS starting from vertex: ";
  int input;
  cin >> input;
  G.BFS(input);

  return 0;
} // main
