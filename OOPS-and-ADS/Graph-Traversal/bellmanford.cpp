#include <iostream>
#include <vector>
#include <limits>

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Function to perform the Bellman-Ford algorithm
void bellmanFord(std::vector<Edge>& edges, int V, int src) {
    // Initialize distances from the source vertex to all other vertices
    std::vector<int> dist(V, std::numeric_limits<int>::max());
    dist[src] = 0;

    // Relax edges V-1 times
    for (int i = 0; i < V - 1; ++i) {
        for (const auto& edge : edges) {
            int u = edge.src;
            int v = edge.dest;
            int weight = edge.weight;
            if (dist[u] != std::numeric_limits<int>::max() && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Check for negative-weight cycles
    for (const auto& edge : edges) {
        int u = edge.src;
        int v = edge.dest;
        int weight = edge.weight;
        if (dist[u] != std::numeric_limits<int>::max() && dist[u] + weight < dist[v]) {
            std::cout << "Graph contains negative-weight cycle" << std::endl;
            return;
        }
    }

    // Print the distances from the source vertex to all other vertices
    std::cout << "Shortest distances from vertex " << src << ":" << std::endl;
    for (int i = 0; i < V; ++i) {
        std::cout << "Vertex " << i << ": " << dist[i] << std::endl;
    }
}

int main() {
    int V, E;
    std::cout << "Enter the number of vertices and edges: ";
    std::cin >> V >> E;

    std::vector<Edge> edges(E);
    std::cout << "Enter the source, destination, and weight of each edge:" << std::endl;
    for (int i = 0; i < E; i++) {
        std::cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    int sourceVertex;
    std::cout << "Enter the source vertex: ";
    std::cin >> sourceVertex;

    bellmanFord(edges, V, sourceVertex);

    return 0;
}
