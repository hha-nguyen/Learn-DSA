#include<iostream>
#include <list>
using namespace std;

class Graph{
    int V; //Num of vertices
    list<int> *adj;
    public: 
        Graph(int V); //Constructor
        void addEdge(int v, int w);
        void BFS(int s);
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V+1];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::BFS(int s) {
    //Mark all the vertices as not visited
    bool *visited = new bool[V+1];
    for (int i = 1; i <= V; ++i) {
        visited[i] = false;
    }

    //create a queue for BFT
    list<int> queue;

    //mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);

    // 'i' will be used to get all adjacent
    // vertices of a vertex
    list<int>::iterator i;
    
    while (!queue.empty()){
        //dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
        adj[s].sort();
        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (i = adj[s].begin(); i != adj[s].end(); ++i){
            if (!visited[*i]) {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

int main() {
    int vertices_num, edge_num;
    cin >> vertices_num >> edge_num;
    Graph g(vertices_num);
    for (int i = 0; i < edge_num; ++i) {
        int v, w;
        cin >> v >> w;
        g.addEdge(v, w);
    }
    g.BFS(1);
}