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

vector<vector<int>> adj, adj_rev;
vector<bool> visited;
vector<int> order;
vector<int> scc_id;

void dfs1(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs1(u);
        }
    }
    order.push_back(v);
}

void dfs2(int v, int compId) {
    visited[v] = true;
    scc_id[v] = compId;
    for (int u : adj_rev[v]) {
        if (!visited[u]) {
            dfs2(u, compId);
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    adj.resize(n);
    adj_rev.resize(n);

    for (int i = 0; i < n; ++i) {
        int key;
        cin >> key;
        key--;
        adj[key].push_back(i);
        adj_rev[i].push_back(key);
    }

    visited.assign(n, false);
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs1(i);
        }
    }

    visited.assign(n, false);
    scc_id.assign(n, -1);
    int scc_count = 0;
    for (int i = n - 1; i >= 0; --i) {
        int v = order[i];
        if (!visited[v]) {
            dfs2(v, scc_count++);
        }
    }

    vector<int> in_degree(scc_count, 0);
    for (int v = 0; v < n; ++v) {
        for (int u : adj[v]) {
            if (scc_id[v] != scc_id[u]) {
                in_degree[scc_id[u]]++;
            }
        }
    }

    int result = 0;
    for (int i = 0; i < scc_count; ++i) {
        if (in_degree[i] == 0) {
            result++;
        }
    }

    cout << result << "\n";
    return 0;
}