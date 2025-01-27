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

void dfs(int v, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[v] = true;
    for (int u = 0; u < adj[v].size(); u++) {
        if (adj[v][u] && !visited[u]) {
            dfs(u, adj, visited);
        }
    }
}
int32_t main() {
    int n, s;
    cin >> n >> s;
    s--;

    vector<vector<int>> adj(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }

    vector<bool> visited(n, false);
    dfs(s, adj, visited);

    int count = 0;
    for (bool v : visited) {
        count += v;
    }

    cout << count;

    return 0;
}