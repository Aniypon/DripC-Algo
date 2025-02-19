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

vector<vector<pair<int, int>>> adj;
vector<int> tin, low;
vector<bool> visited;
set<int> bridges;
int timer;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (auto edge : adj[v]) {
        int to = edge.first;
        int id = edge.second;
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]) {
                bridges.insert(id);
            }
        }
    }
}

int32_t main() {
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    tin.resize(n + 1);
    low.resize(n + 1);
    visited.resize(n + 1, false);
    timer = 0;

    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].pb({v, i});
        adj[v].pb({u, i});
    }

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    cout << bridges.size() << endl;
    for (int bridge : bridges) {
        cout << bridge << " ";
    }
    cout << endl;

    return 0;
}