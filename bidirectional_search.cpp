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

int bidirectionalSearch(Graph &g, int start, int target) {
    vector<bool> visitedStart(g.V, false);
    vector<bool> visitedTarget(g.V, false);

    queue<int> qStart, qTarget;

    qStart.push(start);
    qTarget.push(target);

    visitedStart[start] = true;
    visitedTarget[target] = true;

    while(!qStart.empty() && !qTarget.empty()) {

        int sizeStart = qStart.size();
        while(sizeStart--) {
            int node = qStart.front();
            qStart.pop();

            for(int neighbour : g.adj[node]) {
                if(!visitedStart[neighbour]) {
                    visitedStart[neighbour] = true;
                    qStart.push(neighbour);

                    if(visitedTarget[neighbour])
                        return neighbour;
                }
            }
        }

        int sizeTarget = qTarget.size();
        while(sizeTarget--) {
            int node = qTarget.front();
            qTarget.pop();

            for(int neighbour : g.adj[node]) {
                if(!visitedTarget[neighbour]) {
                    visitedTarget[neighbour] = true;
                    qTarget.push(neighbour);

                    if(visitedStart[neighbour])
                        return neighbour;
                }
            }
        }
    }

    return -1;
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

    int meet = bidirectionalSearch(g, start, target);

    if(meet != -1)
        cout << "Path exists. Meeting at node: " << meet;
    else
        cout << "No path exists";

    return 0;
}
