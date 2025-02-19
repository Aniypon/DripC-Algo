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

void dfs1(int v, vector<bool> &used, vector<int> &order, const vector<vector<int>> &g) {
    used[v] = true;
    for (auto nxt : g[v]) {
        if (!used[nxt])
            dfs1(nxt, used, order, g);
    }
    order.push_back(v);
}

void dfs2(int v, int cl, const vector<vector<int>> &gr, vector<int> &comp, int &minHouse) {
    comp[v] = cl;
    minHouse = min(minHouse, v);
    for (auto nxt : gr[v]) {
        if (comp[nxt] == -1)
            dfs2(nxt, cl, gr, comp, minHouse);
    }
}

int32_t main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1), gr(n + 1);
    vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        gr[v].push_back(u);
        edges.push_back({u, v});
    }

    vector<bool> used(n + 1, false);
    vector<int> order;
    for (int i = 1; i <= n; i++) {
        if (!used[i])
            dfs1(i, used, order, g);
    }

    vector<int> comp(n + 1, -1);
    int compCount = 0;
    vector<int> compMin;

    reverse(order.begin(), order.end());
    for (auto v : order) {
        if (comp[v] == -1) {
            int minHouse = v;
            dfs2(v, compCount, gr, comp, minHouse);
            compMin.push_back(minHouse);
            compCount++;
        }
    }
    vector<int> outdeg(compCount, 0);
    for (int u = 1; u <= n; u++) {
        for (auto v : g[u]) {
            if (comp[u] != comp[v])
                outdeg[comp[u]]++;
        }
    }

    vector<int> ans;
    for (int i = 0; i < compCount; i++) {
        if (outdeg[i] == 0)
            ans.push_back(compMin[i]);
    }
    sort(ans.begin(), ans.end());

    cout << ans.size() << "\n";
    for (auto x : ans)
        cout << x << " ";
    cout << "\n";

    return 0;
}