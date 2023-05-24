#include <iostream>
#include <vector>
#include <queue>
#include <functional>

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Structure to represent a node in the adjacency list
struct Node {
    int vertex, weight;
};

// Function to add an undirected edge between two vertices
void addEdge(std::vector<std::vector<Node>>& adjList, int src, int dest, int weight) {
    Node node;
    node.vertex = dest;
    node.weight = weight;
    adjList[src].push_back(node);

    node.vertex = src;
    adjList[dest].push_back(node);
}

// Function to perform Prim's algorithm
std::vector<Edge> primMST(std::vector<std::vector<Node>>& adjList, int V) {
    std::vector<bool> visited(V, false);  // To track visited vertices
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> pq;  // Priority queue to select minimum-weight edges
    std::vector<Edge> MST;  // Stores the resulting MST

    // Start with vertex 0
    int startVertex = 0;
    visited[startVertex] = true;

    // Add all edges from vertex 0 to the priority queue
    for (const auto& node : adjList[startVertex]) {
        pq.push(node);
    }

    // Loop until the priority queue is empty (all vertices are visited)
    while (!pq.empty()) {
        // Get the minimum-weight edge
        Node minNode = pq.top();
        pq.pop();

        int src = minNode.vertex;
        int weight = minNode.weight;

        // If the destination vertex is already visited, skip this edge
        if (visited[src])
            continue;

        // Mark the destination vertex as visited
        visited[src] = true;

        // Create an edge and add it to the MST
        Edge edge;
        edge.src = src;
        edge.dest = minNode.vertex;
        edge.weight = weight;
        MST.push_back(edge);

        // Add all edges from the destination vertex to the priority queue
        for (const auto& node : adjList[src]) {
            if (!visited[node.vertex]) {
                pq.push(node);
            }
        }
    }

    return MST;
}

// Function to print the MST
void printMST(const std::vector<Edge>& MST) {
    std::cout << "Minimum Spanning Tree:" << std::endl;
    for (const auto& edge : MST) {
        std::cout << edge.src << " -- " << edge.dest << " : " << edge.weight << std::endl;
    }
}

int main() {
    int V, E;
    std::cout << "Enter the number of vertices and edges: ";
    std::cin >> V >> E;

    std::vector<std::vector<Node>> adjList(V);
    std::cout << "Enter the source, destination, and weight of each edge:" << std::endl;
    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        std::cin >> src >> dest >> weight;
        addEdge(adjList, src, dest, weight);
    }

    std::vector<Edge> MST = primMST(adjList, V);
    printMST(MST);

    return 0;
}
