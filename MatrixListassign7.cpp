#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>

using namespace std;

class Graph
{
private:
    int V;
    vector<vector<int>> adjMatrix;
    unordered_map<int, list<int>> adj;

public:
    Graph(int vertices)
    {
        V = vertices;
        adjMatrix.resize(V, vector<int>(V, 0));
    }

    void addEdge(int src, int dest)
    {
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1;
        adj[src].push_back(dest);
        adj[dest].push_back(src);
    }

    void printAdjMatrix()
    {
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < V; ++i)
        {
            for (int j = 0; j < V; ++j)
            {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void printAdjList()
    {
        cout << "Adjacency List:" << endl;
        for (auto i : adj)
        {
            cout << i.first << "-> ";
            for (auto j : i.second)
            {
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    Graph graph(V);

    cout << "Enter the edges (source destination):" << endl;
    for (int i = 0; i < E; ++i)
    {
        int src, dest;
        cin >> src >> dest;
        graph.addEdge(src, dest);
    }

    graph.printAdjMatrix();
    graph.printAdjList();

    return 0;
}
