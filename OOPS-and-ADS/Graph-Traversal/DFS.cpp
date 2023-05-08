#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(vector<vector<int>>& graph, int start, vector<bool>& visited) {
    visited[start] = true;
    cout << start << " ";
    for (int i = 0; i < graph[start].size(); ++i) {
        int neighbor = graph[start][i];
        if (!visited[neighbor]) {
            dfs(graph, neighbor, visited);
        }
    }
}

int main() {
    int n, m; // n = number of nodes, m = number of edges
    cout<<"Enter the number of nodes and edges:";
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cout<<"Enter the two nodes to make edge:";
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // if the graph is undirected
    }
    int start; // starting node for DFS
    cin >> start;
    vector<bool> visited(n + 1, false);
    dfs(graph, start, visited);
    return 0;
}
