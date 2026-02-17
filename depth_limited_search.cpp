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

void dlsUtil(Graph &g, int node, vector<bool> &visited, int limit) {
    if(limit < 0)
        return;

    visited[node] = true;
    cout << node << " ";

    for(int neighbour : g.adj[node]) {
        if(!visited[neighbour]) {
            dlsUtil(g, neighbour, visited, limit - 1);
        }
    }
}

void depthLimitedSearch(Graph &g, int start, int limit) {
    vector<bool> visited(g.V, false);
    dlsUtil(g, start, visited, limit);
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

    int start, limit;
    cin >> start >> limit;

    depthLimitedSearch(g, start, limit);

    return 0;
}
