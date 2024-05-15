#include <bits/stdc++.h>

using namespace std;

class Graph
{
public:
    Graph(int vert);
    void addEdgeDirected(int vertexA, int vertexB, int weight);
    void addEdgeUndirected(int vertexA, int vertexB, int weight);
    void printList();
    void BFS(int start);

private:
    int vertices;
    vector<pair<int, int>> *adjacencyList; 
};

Graph::Graph(int vertices)
{
    this->vertices = vertices;
    adjacencyList = new vector<pair<int, int>>[vertices];
}

void Graph::addEdgeDirected(int vertexA, int vertexB, int weight)
{
    adjacencyList[vertexA].push_back({vertexB, weight});
}

void Graph::addEdgeUndirected(int vertexA, int vertexB, int weight)
{
    adjacencyList[vertexA].push_back({vertexB, weight});
    adjacencyList[vertexB].push_back({vertexA, weight});
}

void Graph::printList() 
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
}

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
}

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
    D.printList(); // print
    cout << "BFS starting from vertex 0:\n";
    D.BFS(0);


    Graph UD(10); // Create an UNDIRECTIONAL adjacency list with 10 vertices WEIGHTED EDGES
    UD.addEdgeUndirected(0, 1, 3);
    UD.addEdgeUndirected(1, 2, 4);
    UD.addEdgeUndirected(1, 3, 2);
    UD.addEdgeUndirected(2, 4, 5);
    UD.addEdgeUndirected(3, 4, 1);
    UD.addEdgeUndirected(4, 4, 6);
    UD.addEdgeUndirected(5, 7, 7);
    UD.addEdgeUndirected(5, 8, 8);
    UD.addEdgeUndirected(6, 9, 7);
    UD.addEdgeUndirected(9, 3, 8);
    cout << "UNDIRECTED:\n";
    UD.printList(); // print

    int input;
    cin >> input;
    cout << "BFS starting from vertex " << input << endl;
    UD.BFS(0);
    
    return 0;
}