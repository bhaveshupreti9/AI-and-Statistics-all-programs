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

void hillClimbing(Graph &g, int start, int target) {
    int current = start;
    cout << current << " ";

    while(current != target) {
        int best = -1;
        int bestHeuristic = g.heuristic[current];

        for(int neighbour : g.adj[current]) {
            if(g.heuristic[neighbour] < bestHeuristic) {
                bestHeuristic = g.heuristic[neighbour];
                best = neighbour;
            }
        }

        if(best == -1) {
            cout << "\nStuck at local optimum";
            return;
        }

        current = best;
        cout << current << " ";
    }

    cout << "\nTarget Reached";
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

    hillClimbing(g, start, target);

    return 0;
}
