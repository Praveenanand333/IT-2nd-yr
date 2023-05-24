#include <iostream>
#include <vector>
#include <queue>
#include <climits>

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
    std::vector<int> key(V, INT_MAX);  // Key values used to pick the minimum weight edge
    std::vector<int> parent(V, -1);  // Store the MST

    // Start with vertex 0
    int startVertex = 0;
    key[startVertex] = 0;

    // Create a priority queue to select the minimum-weight edge
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

    // Add the start vertex to the priority queue
    pq.push(std::make_pair(0, startVertex));

    // Loop until all vertices are included in the MST
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        visited[u] = true;

        // Traverse all adjacent vertices of u
        for (const auto& node : adjList[u]) {
            int v = node.vertex;
            int weight = node.weight;

            // If v is not visited and the weight of the edge (u,v) is smaller than the current key of v,
            // update the key value and parent of v
            if (!visited[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                pq.push(std::make_pair(key[v], v));
            }
        }
    }

    // Construct the MST from the parent array
    std::vector<Edge> MST;
    for (int i = 1; i < V; ++i) {
        Edge edge;
        edge.src = parent[i];
        edge.dest = i;
        edge.weight = key[i];
        MST.push_back(edge);
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
