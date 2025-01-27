#include <bits/stdc++.h>
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

void dfs(int v, int parent, vector<vector<int>>& adj, vector<int>& dist) {
    for (int u : adj[v]) {
        if (u != parent) {
            dist[u] = dist[v] + 1;
            dfs(u, v, adj, dist);
        }
    }
}

int32_t main() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist1(n + 1, 0);
    dfs(1, -1, adj, dist1);

    int max_dist = 0, far_vertex = 1;
    for (int i = 1; i <= n; i++) {
        if (dist1[i] > max_dist) {
            max_dist = dist1[i];
            far_vertex = i;
        }
    }

    vector<int> dist2(n + 1, 0);
    dfs(far_vertex, -1, adj, dist2);

    int diameter = 0;
    for (int i = 1; i <= n; i++) {
        diameter = max(diameter, dist2[i]);
    }

    cout << diameter + 1;

    return 0;
}