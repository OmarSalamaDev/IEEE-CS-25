#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int maxCost = 0;

void dfs(
    int curr,
    set<int>& visited,
    int current_cost,
    const vector<vector<pair<int, int>>>& adj
) {
    maxCost = max(maxCost, current_cost);
    visited.insert(curr);

    for (const auto& edge : adj[curr]) {
        int neighbor = edge.first;
        int cost = edge.second;
        if (visited.find(neighbor) == visited.end()) {
            set<int> next_visited = visited; 
            dfs(neighbor, next_visited, current_cost + cost, adj);
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    set<int> visited;
    dfs(0, visited, 0, adj);

    cout << maxCost << endl;

    return 0;
}