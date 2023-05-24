#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Structure to represent a weighted edge
struct Edge {
    int destination;
    int weight;

    Edge(int dest, int w) : destination(dest), weight(w) {}
};

// Function to implement Dijkstra's algorithm
void Dijkstra(vector<vector<Edge>>& graph, int source) {
    int numVertices = graph.size();
    vector<int> distance(numVertices, INT_MAX);
    vector<bool> visited(numVertices, false);
    distance[source] = 0;

    // Priority queue to store vertices and their distances
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        visited[u] = true;

        // Traverse all adjacent vertices of u
        for (const Edge& edge : graph[u]) {
            int v = edge.destination;
            int weight = edge.weight;

            // Relax the edge if a shorter path is found
            if (!visited[v] && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                pq.push({distance[v], v});
            }
        }
    }

    // Print the shortest distances from the source vertex
    cout << "Shortest distances from source vertex " << source << ":" << endl;
    for (int i = 0; i < numVertices; i++) {
        if (distance[i] == INT_MAX) {
            cout << i << ": Not reachable" << endl;
        } else {
            cout << i << ": " << distance[i] << endl;
        }
    }
}

int main() {
    int numVertices = 6;
    int source = 0;
    vector<vector<Edge>> graph(numVertices);

    // Add edges to the graph
    graph[0].push_back(Edge(1, 2));
    graph[0].push_back(Edge(2, 4));
    graph[1].push_back(Edge(2, 1));
    graph[1].push_back(Edge(3, 7));
    graph[2].push_back(Edge(4, 3));
    graph[3].push_back(Edge(4, 2));
    graph[3].push_back(Edge(5, 1));
    graph[4].push_back(Edge(5, 5));

    // Apply Dijkstra's algorithm
    Dijkstra(graph, source);

    return 0;
}
