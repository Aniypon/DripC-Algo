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
const int MOD = 1000000007;

int timer;
vector<int> tin, low;
vector<pair<int, int>> bridges;

void dfs_bridges(int v, int parent, const vector<vector<int>> &g) {
    tin[v] = low[v] = ++timer;
    for (auto to : g[v]) {
        if (to == parent)
            continue;
        if (tin[to] != -1) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs_bridges(to, v, g);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]) {
                bridges.push_back({min(v, to), max(v, to)});
            }
        }
    }
}

int32_t main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    tin.assign(n + 1, -1);
    low.assign(n + 1, -1);
    timer = 0;

    for (int i = 1; i <= n; i++) {
        if (tin[i] == -1)
            dfs_bridges(i, -1, g);
    }

    if (bridges.empty()) {
        cout << 1 << " " << n % MOD << "\n";
        return 0;
    }

    set<pair<int, int>> bridgeSet;
    for (auto &p : bridges)
        bridgeSet.insert(p);

    vector<int> comp(n + 1, -1);
    int compCount = 0;
    function<void(int, int)> dfs_comp = [&](int v, int curComp) {
        comp[v] = curComp;
        for (auto to : g[v]) {
            pair<int, int> edge = {min(v, to), max(v, to)};
            if (bridgeSet.count(edge))
                continue;
            if (comp[to] == -1)
                dfs_comp(to, curComp);
        }
    };

    for (int i = 1; i <= n; i++) {
        if (comp[i] == -1) {
            dfs_comp(i, compCount);
            compCount++;
        }
    }

    vector<int> compSize(compCount, 0);
    for (int i = 1; i <= n; i++) {
        compSize[comp[i]]++;
    }

    vector<int> deg(compCount, 0);
    for (auto &edge : bridges) {
        int u = edge.first, v = edge.second;
        deg[comp[u]]++;
        deg[comp[v]]++;
    }

    int leavesCount = 0;
    int ways = 1;
    for (int i = 0; i < compCount; i++) {
        if (deg[i] == 1) {
            leavesCount++;
            ways = (ways * compSize[i]) % MOD;
        }
    }

    cout << leavesCount << " " << ways % MOD << "\n";

    return 0;
}