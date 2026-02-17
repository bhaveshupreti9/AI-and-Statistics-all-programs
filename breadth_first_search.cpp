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

void bfs(Graph &g, int start) {
    vector<bool> visited(g.V, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for(int neighbour : g.adj[node]) {
            if(!visited[neighbour]) {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
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

    int start;
    cin >> start;

    bfs(g, start);

    return 0;
}
