
// //   BFS ready
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <vector>
#include <queue>

using namespace std;

void prepareAdjList(unordered_map<int, list<int>> &adjList, const vector<pair<int, int>> &edges) {
    for (auto &edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

void bfs(unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node) {
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while (!q.empty()) {
        int frontNode = q.front();
        q.pop();

        // Store frontNode into ans
        ans.push_back(frontNode);

        // Traverse all neighbors of frontNode
        for (int neighbor : adjList.at(frontNode)) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

vector<int> BFS(const vector<pair<int, int>> &edges) {
    unordered_map<int, list<int>> adjList;
    vector<int> ans;
    unordered_map<int, bool> visited;

    prepareAdjList(adjList, edges);

    // Find all unique vertices
    unordered_set<int> vertices;
    for (const auto &edge : edges) {
        vertices.insert(edge.first);
        vertices.insert(edge.second);
    }

    // Traverse all components of the graph
    for (int vertex : vertices) {
        if (!visited[vertex]) {
            bfs(adjList, visited, ans, vertex);
        }
    }

    return ans;
}

int main() {
    vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 3}, {1, 4}};
    pair<int, int> temp = {5, 6};
    edges.push_back(temp);

    vector<int> result = BFS(edges);

    for (int node : result) {
        cout << node << "  ";
    }

    return 0;
}


// #include <iostream>
// #include <unordered_map>
// #include <list>
// #include <vector>

// using namespace std;

// class Graph {
// public:
//     // Function to add an edge to the graph
//     void addEdge(int v, int w) {
//         adj[v].push_back(w);
//         adj[w].push_back(v);  // Add reverse edge for undirected graph
//     }

//     // Function to perform DFS traversal for all components
//     void DFS() {
//         unordered_map<int, bool> visited;
//         for (const auto &vertex : adj) {
//             if (!visited[vertex.first]) {
//                 DFSUtil(vertex.first, visited);
//             }
//         }
//     }

// private:
//     unordered_map<int, list<int>> adj; // Adjacency list

//     // Utility function for DFS traversal
//     void DFSUtil(int v, unordered_map<int, bool> &visited) {
//         visited[v] = true;
//         cout << v << " ";
//         for (int neighbor : adj[v]) {
//             if (!visited[neighbor]) {
//                 DFSUtil(neighbor, visited);
//             }
//         }
//     }
// };

// int main() {
//     Graph g;
//     int numEdges, v, w;

//     cout << "Enter the number of edges: ";
//     cin >> numEdges;

//     cout << "Enter the edges (format: v w):" << endl;
//     for (int i = 0; i < numEdges; ++i) {
//         cin >> v >> w;
//         g.addEdge(v, w);
//     }

//     cout << "Depth First Traversal for all components:\n";
//     g.DFS();

//     return 0;
// }
