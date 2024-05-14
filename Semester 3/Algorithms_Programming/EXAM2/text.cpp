#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <limits>

using namespace std;

template <typename T>
class Graph {
private:
    unordered_map<int, vector<pair<int, T>>> adjList;
    bool directed;

public:
    Graph(bool directed = false) : directed(directed) {}

    void addEdge(int src, int dest, T weight = T()) {
        adjList[src].push_back(make_pair(dest, weight));
        if (!directed) {
            adjList[dest].push_back(make_pair(src, weight));
        }
    }

    void printGraph() {
        for (auto& vertex : adjList) {
            cout << vertex.first << " : ";
            for (auto& neighbor : vertex.second) {
                cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
            }
            cout << endl;
        }
    }

    vector<pair<int, T>> getNeighbors(int vertex) {
        return adjList[vertex];
    }

    vector<pair<int, T>> primsMST() {
        priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;
        vector<pair<int, T>> mst;

        // Initialize distances to infinity and mark all vertices as unvisited
        for (auto& vertex : adjList) {
            visited[vertex.first] = false;
            parent[vertex.first] = -1;
        }

        // Start from the first vertex
        pq.push(make_pair(0, adjList.begin()->first));

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int u = top.second;
            T u_dist = top.first;

            // Skip if vertex already visited
            if (visited[u])
                continue;

            // Mark current vertex as visited
            visited[u] = true;
            if (parent[u] != -1)
                mst.push_back(make_pair(u, u_dist));

            // Explore neighbors
            for (auto& neighbor : adjList[u]) {
                int v = neighbor.first;
                T v_dist = neighbor.second;
                if (!visited[v]) {
                    pq.push(make_pair(v_dist, v));
                    parent[v] = u;
                }
            }
        }

        return mst;
    }
};

int main() {
    Graph<int> g;
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    cout << "Graph:\n";
    g.printGraph();

    cout << "\nMinimum Spanning Tree (Prim's Algorithm):\n";
    auto mst = g.primsMST();
    for (auto& edge : mst) {
        cout << edge.first << " - " << edge.second << endl;
    }

    return 0;
}