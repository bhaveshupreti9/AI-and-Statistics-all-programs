#include<bits/stdc++.h>
using namespace std;

struct Graph {
    int V;
    vector<vector<int>> adj;
};

void addEdge(Graph &g, int u, int v) {
    g.adj[u].push_back(v);
    g.adj[v].push_back(u);
}

void dfsUtil(Graph &g, int node, vector<bool> &visited) {
    visited[node] = true;
    cout << node << " ";

    for(int neighbour : g.adj[node]) {  
        if(!visited[neighbour]) {
            dfsUtil(g, neighbour, visited);
        }
    }
}

void dfs(Graph &g, int start) {
    vector<bool> visited(g.V, false);
    dfsUtil(g, start, visited);
}

int main() {
    Graph g;
    int edges;

    cin >> g.V >> edges;
    g.adj.resize(g.V);

    for(int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(g, u, v);
    }

    int start;
    cin >> start;

    dfs(g, start);

    return 0;
}
