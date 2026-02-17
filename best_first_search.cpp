#include<bits/stdc++.h>
using namespace std;

struct Graph {
    int V;
    vector<vector<int>> adj;
    vector<int> heuristic;
};

void addEdge(Graph &g, int u, int v) {
    g.adj[u].push_back(v);
    g.adj[v].push_back(u);
}

void greedyBestFirstSearch(Graph &g, int start, int target) {
    vector<bool> visited(g.V, false);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({g.heuristic[start], start});
    visited[start] = true;

    while(!pq.empty()) {
        int node = pq.top().second;
        pq.pop();

        cout << node << " ";

        if(node == target) {
            cout << "\nTarget Found";
            return;
        }

        for(int neighbour : g.adj[node]) {
            if(!visited[neighbour]) {
                visited[neighbour] = true;
                pq.push({g.heuristic[neighbour], neighbour});
            }
        }
    }

    cout << "\nTarget Not Found";
}

int main() {
    Graph g;
    int edges;

    cin >> g.V >> edges;
    g.adj.resize(g.V);
    g.heuristic.resize(g.V);

    for(int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(g, u, v);
    }

    for(int i = 0; i < g.V; i++)
        cin >> g.heuristic[i];

    int start, target;
    cin >> start >> target;

    greedyBestFirstSearch(g, start, target);

    return 0;
}
