#include <iostream>  
#include <vector>  
#include <queue>  
using namespace std;  
// This function performs a BFS search on a graph represented as an adjacency list.  
// The graph is assumed to be undirected.  
//  
// Parameters:  
// - adj_list: a vector of vectors representing the adjacency list of the graph  
// - start: the index of the starting vertex  
// - target: the index of the target vertex (optional)  
//  
// Returns:  
// - a vector of integers representing the BFS traversal order of the graph,  
//   starting from the start vertex  
// - an empty vector if the target vertex is not found (when the target is specified)  
vector<int> bfs(const vector<vector<int>>& adj_list, int start, int target = -1)  
{  
    int n = adj_list.size();  
    vector<bool> visited(n, false);  // a boolean array to track visited vertices  
    vector<int> order;  // a vector to store the BFS traversal order  
  
    queue<int> q;  // a queue to hold the vertices to be visited  
    q.push(start);  // add the starting vertex to the queue  
    visited[start] = true;  // mark the starting vertex as visited  
    while (!q.empty())  
    {  
        int u = q.front();  // get the next vertex in the queue  
        q.pop();  // remove the vertex from the queue  
  
        order.push_back(u);  // add the vertex to the traversal order  
  
        // add all the unvisited neighbors of u to the queue  
        for (int v : adj_list[u])  
        {  
            if (!visited[v])  
            {  
                q.push(v);  
                visited[v] = true;  
            }  
        }  
    }  
    if (target != -1 && !visited[target])  
    {  
        // the target vertex was not found, return an empty vector  
        return {};  
    }  
    return order;  
}  
int main()  
{  
    // create an adjacency list for a graph with 5 vertices  
    vector<vector<int>> adj_list = {  
        {1, 2},  // vertex 0 has neighbors 1 and 2  
        {0, 3, 4},  // vertex 1 has neighbors 0, 3, and 4  
        {0, 4},  // vertex 2 has neighbors 0 and 4  
        {1, 4},  // vertex 3 has neighbors 1 and 4  
        {1, 2, 3}  // vertex 4 has neighbors 1, 2, and 3  
    };  
    // perform a BFS search starting from vertex 0  
    vector<int> order = bfs(adj_list, 0);  
    // print the traversal order  
    cout << "BFS traversal order: ";  
    for (int i : order)  
    {  
        cout << i << " ";  
    }  
    cout << endl;  
  
    return 0;  
}  