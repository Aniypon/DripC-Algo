#include <bits/stdc++.h>
using namespace std;

#define double long double
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

const int inf = 1e15;
const int ninf = -1e15;
const double EPS = 1e-9;

vector<vector<int>> adj;
vector<int> parent, visited;
int cycle_start, cycle_end;

bool dfs(int v, int par) {
    visited[v] = 1;
    for (int u : adj[v]) {
        if (u == par)
            continue;
        if (visited[u]) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
        parent[u] = v;
        if (dfs(u, v))
            return true;
    }
    return false;
}

int32_t main() {
    int n;
    cin >> n;
    adj.resize(n);
    parent.resize(n, -1);
    visited.resize(n, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x;
            cin >> x;
            if (x == 1) {
                adj[i].pb(j);
            }
        }
    }

    cycle_start = -1;
    for (int v = 0; v < n; ++v) {
        if (!visited[v] && dfs(v, -1)) {
            break;
        }
    }

    if (cycle_start == -1) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    vector<int> cycle;
    cycle.pb(cycle_start);
    for (int v = cycle_end; v != cycle_start; v = parent[v]) {
        cycle.pb(v);
    }
    cycle.pb(cycle_start);
    reverse(all(cycle));

    cycle.pop_back();

    cout << cycle.size() << "\n";
    for (int v : cycle) {
        cout << v + 1 << " ";
    }
    cout << "\n";
    return 0;
}