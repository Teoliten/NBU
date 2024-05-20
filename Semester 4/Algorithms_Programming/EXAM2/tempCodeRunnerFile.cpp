#include <iostream>
#include <vector>
#include <queue>

using namespace std;

template<typename T>
class Graph {
public:
    Graph(bool isDirected);

    void addEdge(T from, T to, int weight = 1);
    void BFS(T start);

private:
    vector<vector<pair<T, int>>> adjacencyList;
    bool isDirected;
};

template<typename T>
Graph<T>::Graph(bool isDirected){
    this->isDirected = isDirected;
}

template<typename T>
void Graph<T>::addEdge(T from, T to, int weight) {
    if (from >= adjacencyList.size() || to >= adjacencyList.size()) {
        int newSize = max(from, to) + 1;
        adjacencyList.resize(newSize);
    }
    adjacencyList[from].push_back(make_pair(to, weight));
    if (!isDirected) {
        adjacencyList[to].push_back(make_pair(from, weight));
    }
}

template<typename T>
void Graph<T>::BFS(T start) {
    vector<bool> visited(adjacencyList.size(), false);
    queue<T> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        T current = q.front();
        q.pop();
        cout << current << " ";

        for (auto neighbor : adjacencyList[current]) {
            if (!visited[neighbor.first]) {
                q.push(neighbor.first);
                visited[neighbor.first] = true;
            }
        }
    }
    cout << endl;
}

int main() {
    Graph<int> graph;

    // Adding edges
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(2, 5);
    graph.addEdge(3, 6);
    graph.addEdge(4, 7);
    graph.addEdge(5, 8);

    cout << "BFS traversal starting from node 0: ";
    graph.BFS(0);

    return 0;
}
