#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

const int inf = 1e15;
const int ninf = -1e15;
const double EPS = 1e-9;

void dfs(int v, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& component) {
    visited[v] = true;
    component.push_back(v + 1);
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs(u, adj, visited, component);
        }
    }
}

int32_t main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n, false);
    vector<vector<int>> components;

    for (int v = 0; v < n; v++) {
        if (!visited[v]) {
            vector<int> component;
            dfs(v, adj, visited, component);
            components.push_back(component);
        }
    }

    cout << components.size() << endl;
    for (auto& comp : components) {
        cout << comp.size() << endl;
        for (int v : comp) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}