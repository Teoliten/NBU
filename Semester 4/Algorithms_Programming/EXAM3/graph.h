#ifndef GRAPH_H
#define GRAPH_H

#include <bits/stdc++.h>

using namespace std;

class Graph {
public:
    Graph(int V);                                   // Constructor
    void addEdge(int u, int v, int w);              // add edge to graph
    bool bfs(int s, int t, vector<int>& parent);    // breadth first search
    int fordFulkerson(int s, int t);                // ford fulkerson algorithm, from vertex s, to t
private:
    int vertices;                                   // Number of vertices
    vector<list<pair<int, int>>> adj;               // Adjacency list
    vector<vector<int>> residualGraph;              // Residual graph
}; // class Graph

Graph::Graph(int vertices) {
    this->vertices = vertices;
    adj.resize(vertices);
    residualGraph.resize(vertices, vector<int>(vertices, 0));
} // constructor

void Graph::addEdge(int u, int v, int w) {
    adj[u].push_back({v, w});
    residualGraph[u][v] = w;
} // addEdge

// breadth first search to find if there is a path from source to sink
bool Graph::bfs(int s, int t, vector<int>& parent) {
    vector<bool> visited(vertices, false);
    queue<int> queue;

    queue.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!queue.empty()) {
        int u = queue.front();
        queue.pop();

        for (const auto& edge : adj[u]) {
            int v = edge.first;
            int capacity = residualGraph[u][v];

            if (!visited[v] && capacity > 0) {
                if (v == t) {
                    parent[v] = u;
                    return true;
                }
                queue.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return false;
}//bfs

// ford fulkerson function for finding maximum flow
int Graph::fordFulkerson(int s, int t) {
    vector<int> parent(vertices);
    int maxFlow = 0;

    // increase the flow while there is a path from source to sink
    while (bfs(s, t, parent)) {
        // find the maximum flow through the path found by BFS
        int pathFlow = 999999;
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, residualGraph[u][v]);
        }

        // update residual capacities of the edges and reverse edges along the path
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            residualGraph[u][v] -= pathFlow;
            residualGraph[v][u] += pathFlow;
        }

        maxFlow += pathFlow; // add path flow
    }
    return maxFlow;
}//fordFulkerson

#endif