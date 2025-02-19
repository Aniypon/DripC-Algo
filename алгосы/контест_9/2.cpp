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

void dfs1(int v, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& order) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs1(u, adj, visited, order);
        }
    }
    order.pb(v);
}

void dfs2(int v, vector<vector<int>>& adj_rev, vector<bool>& visited, vector<int>& component) {
    visited[v] = true;
    component.pb(v);
    for (int u : adj_rev[v]) {
        if (!visited[u]) {
            dfs2(u, adj_rev, visited, component);
        }
    }
}

int32_t main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n), adj_rev(n), scc;
    vector<int> order, component, component_id(n);
    vector<bool> visited(n, false);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v; 
        adj[u].pb(v);
        adj_rev[v].pb(u);
    }

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs1(i, adj, visited, order);
        }
    }

    fill(visited.begin(), visited.end(), false);
    reverse(order.begin(), order.end());

    int scc_count = 0;
    for (int v : order) {
        if (!visited[v]) {
            dfs2(v, adj_rev, visited, component);
            for (int u : component) {
                component_id[u] = scc_count;
            }
            scc.pb(component);
            component.clear();
            ++scc_count;
        }
    }

    cout << scc_count << endl;
    for (int i = 0; i < n; ++i) {
        cout << component_id[i] + 1 << " ";
    }
    cout << endl;

    return 0;
}