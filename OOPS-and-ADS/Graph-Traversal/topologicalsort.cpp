#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to perform topological sort
vector<int> topologicalSort(vector<vector<int>>& graph, int numCourses) {
    vector<int> inDegree(numCourses, 0);
    vector<int> result;
    queue<int> q;

    // Calculate the in-degree of each vertex
    for (int i = 0; i < numCourses; i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            int course = graph[i][j];
            inDegree[course]++;
        }
    }

    // Enqueue vertices with in-degree 0
    for (int i = 0; i < numCourses; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    // Perform topological sort
    while (!q.empty()) {
        int course = q.front();
        q.pop();
        result.push_back(course);

        // Reduce the in-degree of adjacent vertices
        for (int i = 0; i < graph[course].size(); i++) {
            int adjacentCourse = graph[course][i];
            inDegree[adjacentCourse]--;

            // Enqueue vertices with in-degree 0
            if (inDegree[adjacentCourse] == 0) {
                q.push(adjacentCourse);
            }
        }
    }

    // If not all vertices are included, there is a cycle in the graph
    if (result.size() != numCourses) {
        result.clear(); // Clear the result to indicate failure (cycle detected)
    }

    return result;
}

int main() {
    int numCourses = 6;
    vector<vector<int>> graph(numCourses);

    // Add edges to the graph
    graph[5].push_back(2);
    graph[5].push_back(0);
    graph[4].push_back(0);
    graph[4].push_back(1);
    graph[4].push_back(2);
    graph[2].push_back(3);
    graph[3].push_back(1);

    // Perform topological sort
    vector<int> sortedCourses = topologicalSort(graph, numCourses);

    // Print the result
    if (sortedCourses.empty()) {
        cout << "Cycle detected. Topological sort is not possible." << endl;
    } else {
        cout << "Topological Sort: ";
        for (int i = 0; i < sortedCourses.size(); i++) {
            cout << sortedCourses[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
