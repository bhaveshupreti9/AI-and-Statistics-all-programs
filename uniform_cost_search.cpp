#include<bits/stdc++.h>
using namespace std;

struct Graph {
    int V;
    vector<vector<pair<int,int>>> adj;
};

void addEdge(Graph &g, int u, int v, int w) {
    g.adj[u].push_back({v, w});
    g.adj[v].push_back({u, w});
}

void uniformCostSearch(Graph &g, int start, int target) {
    vector<int> cost(g.V, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    cost[start] = 0;
    pq.push({0, start});

    while(!pq.empty()) {
        int currCost = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(node == target) {
            cout << "Minimum Cost: " << currCost;
            return;
        }

        for(auto neighbour : g.adj[node]) {
            int nextNode = neighbour.first;
            int weight = neighbour.second;

            if(cost[nextNode] > currCost + weight) {
                cost[nextNode] = currCost + weight;
                pq.push({cost[nextNode], nextNode});
            }
        }
    }

    cout << "Target not reachable";
}

int main() {
    Graph g;
    int edges;

    cin >> g.V >> edges;
    g.adj.resize(g.V);

    for(int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(g, u, v, w);
    }

    int start, target;
    cin >> start >> target;

    uniformCostSearch(g, start, target);

    return 0;
}
