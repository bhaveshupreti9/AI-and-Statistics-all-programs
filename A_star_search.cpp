#include<bits/stdc++.h>
using namespace std;

struct Graph {
    int V;
    vector<vector<pair<int,int>>> adj;
    vector<int> heuristic;
};

void addEdge(Graph &g, int u, int v, int w) {
    g.adj[u].push_back({v, w});
    g.adj[v].push_back({u, w});
}

void aStar(Graph &g, int start, int target) {
    vector<int> gCost(g.V, INT_MAX);
    vector<bool> visited(g.V, false);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    gCost[start] = 0;
    pq.push({g.heuristic[start], start});

    while(!pq.empty()) {
        int node = pq.top().second;
        pq.pop();

        if(visited[node])
            continue;

        visited[node] = true;
        cout << node << " ";

        if(node == target) {
            cout << "\nMinimum Cost: " << gCost[node];
            return;
        }

        for(auto neighbour : g.adj[node]) {
            int nextNode = neighbour.first;
            int weight = neighbour.second;

            if(gCost[nextNode] > gCost[node] + weight) {
                gCost[nextNode] = gCost[node] + weight;
                int fCost = gCost[nextNode] + g.heuristic[nextNode];
                pq.push({fCost, nextNode});
            }
        }
    }

    cout << "\nTarget Not Reachable";
}

int main() {
    Graph g;
    int edges;

    cin >> g.V >> edges;
    g.adj.resize(g.V);
    g.heuristic.resize(g.V);

    for(int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(g, u, v, w);
    }

    for(int i = 0; i < g.V; i++)
        cin >> g.heuristic[i];

    int start, target;
    cin >> start >> target;

    aStar(g, start, target);

    return 0;
}
