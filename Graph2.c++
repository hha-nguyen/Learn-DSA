#include <bits/stdc++.h>
using namespace std;

class Graph {
    public:
    map<int, bool> visited;
    map<int, list<int>> adj;
    // function to add an edge to graph
    void addEdge(int v, int w);

    // DFS traversal of the vertices
    // reachable from v
    void DFS(int v);
};

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::DFS(int v) {
    visited[v] = true;
    cout << v << " ";
    adj[v].sort();
    //Recursion for all the vertices adj to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i) {
        if (!visited[*i])
            DFS(*i);
    }
}

int main() {
    int v_num, e_num;
    cin >> v_num >> e_num;
    Graph g;
    for (int i = 1; i <= e_num; ++i) {
        int v, w;
        cin >> v >> w;
        g.addEdge(v, w);
    }
    g.DFS(1);
}