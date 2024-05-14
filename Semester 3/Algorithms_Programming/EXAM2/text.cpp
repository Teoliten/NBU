#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <climits> // For INT_MAX

using namespace std;

template <typename WeightType>
class Graph {
public:
    Graph() {}

    void addEdge(int u, int v, WeightType weight, bool directed = false) {
        adjList[u].emplace_back(v, weight);
        if (!directed) {
            adjList[v].emplace_back(u, weight);
        }
    }

    WeightType findMinKey(const set<int>& vertices, const vector<WeightType>& key) {
        WeightType minKey = INT_MAX;
        int minVertex = -1;
        for (int v : vertices) {
            if (key[v] < minKey) {
                minKey = key[v];
                minVertex = v;
            }
        }
        return minVertex;
    }

    void primMST() {
        vector<WeightType> key(adjList.size(), INT_MAX); // Initialize key values
        vector<int> parent(adjList.size(), -1); // Initialize parent array
        set<int> vertices; // Set of vertices not yet included in MST

        // Start with vertex 0
        key[0] = 0;
        vertices.insert(0);

        while (!vertices.empty()) {
            int u = findMinKey(vertices, key);
            vertices.erase(u);

            for (const auto& [v, weight] : adjList[u]) {
                if (vertices.count(v) && weight < key[v]) {
                    parent[v] = u;
                    key[v] = weight;
                }
            }
        }

        // Print MST
        cout << "Minimum Spanning Tree:" << endl;
        for (int i = 1; i < adjList.size(); ++i) {
            cout << "Edge: (" << parent[i] << ", " << i << ") Weight: " << key[i] << endl;
        }
    }

private:
    map<int, vector<pair<int, WeightType>>> adjList;
};

int main() {
    Graph<int> weightedGraph;
    weightedGraph.addEdge(0, 1, 9);
    weightedGraph.addEdge(0, 2, 75);
    weightedGraph.addEdge(1, 2, 95);
    weightedGraph.addEdge(1, 3, 19);
    weightedGraph.addEdge(1, 4, 42);
    weightedGraph.addEdge(2, 3, 51);
    weightedGraph.addEdge(2, 4, 66);

    weightedGraph.primMST();

    return 0;
}