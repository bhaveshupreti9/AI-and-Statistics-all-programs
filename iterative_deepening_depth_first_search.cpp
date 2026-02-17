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

bool dls(Graph &g, int node, int target, int limit, vector<bool> &visited) {
    if(node == target) {
        cout << node << " ";
        return true;
    }

    if(limit <= 0)
        return false;

    visited[node] = true;
    cout << node << " ";

    for(int neighbour : g.adj[node]) {
        if(!visited[neighbour]) {
            if(dls(g, neighbour, target, limit - 1, visited))
                return true;
        }
    }

    return false;
}

void iddfs(Graph &g, int start, int target) {
    for(int depth = 0; depth < g.V; depth++) {
        vector<bool> visited(g.V, false);
        if(dls(g, start, target, depth, visited))
            return;
        cout << endl;
    }
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

    int start, target;
    cin >> start >> target;

    iddfs(g, start, target);

    return 0;
}
