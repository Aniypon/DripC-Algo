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

struct PairHash {
    size_t operator()(const pair<int, int> &p) const {
        return std::hash<int>()(p.first) ^ (std::hash<int>()(p.second) << 1);
    }
};

struct DSU {
    vector<int> parent;
    DSU(int n) : parent(n + 1) {
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }
    int find(int a) {
        return parent[a] == a ? a : parent[a] = find(parent[a]);
    }
    void unite(int a, int b) {
        a = find(a), b = find(b);
        if (a != b)
            parent[b] = a;
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<array<int, 3>> cushions(m);
    unordered_map<pair<int, int>, int, PairHash> freq;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        cushions[i] = {a, b, c};
        vector<pair<int, int>> edges = {{min(a, b), max(a, b)}, {min(a, c), max(a, c)}, {min(b, c), max(b, c)}};
        for (auto &e : edges) {
            freq[e]++;
        }
    }

    vector<vector<int>> graph(n + 1);
    for (auto &entry : freq) {
        int u = entry.first.first, v = entry.first.second;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    DSU dsu(n);
    for (auto &entry : freq) {
        if (entry.second >= 2) {
            int u = entry.first.first, v = entry.first.second;
            dsu.unite(u, v);
        }
    }

    unordered_map<pair<int, int>, int, PairHash> uniqComp;
    for (auto &entry : freq) {
        if (entry.second == 1) {
            int u = entry.first.first, v = entry.first.second;
            int cu = dsu.find(u), cv = dsu.find(v);
            if (cu == cv)
                continue;
            pair<int, int> compEdge = {min(cu, cv), max(cu, cv)};
            uniqComp[compEdge]++;
        }
    }

    vector<int> critical;
    for (int i = 0; i < m; i++) {
        auto [a, b, c] = cushions[i];
        int ca = dsu.find(a), cb = dsu.find(b), cc = dsu.find(c);
        if (ca == cb && ca == cc)
            continue;

        set<int> comps = {ca, cb, cc};
        unordered_map<pair<int, int>, int, PairHash> blocked;
        vector<pair<int, int>> triEdges = {{min(a, b), max(a, b)}, {min(a, c), max(a, c)}, {min(b, c), max(b, c)}};
        for (auto &e : triEdges) {
            if (freq[e] == 1) {
                int u = e.first, v = e.second;
                int cu = dsu.find(u), cv = dsu.find(v);
                if (cu == cv)
                    continue;
                pair<int, int> compEdge = {min(cu, cv), max(cu, cv)};
                blocked[compEdge] = 1;
            }
        }

        vector<int> compList(all(comps));
        auto connectedSubgraph = [&]() -> bool {
            int k = compList.size();
            unordered_map<int, vector<int>> smallGraph;
            for (int i = 0; i < k; i++) {
                for (int j = i + 1; j < k; j++) {
                    int x = compList[i], y = compList[j];
                    pair<int, int> key = {min(x, y), max(x, y)};
                    int available = 0;
                    if (uniqComp.count(key))
                        available = uniqComp[key];
                    if (blocked.count(key))
                        available -= blocked[key];
                    if (available > 0) {
                        smallGraph[x].push_back(y);
                        smallGraph[y].push_back(x);
                    }
                }
            }
            set<int> vis;
            function<void(int)> dfs = [&](int v) {
                vis.insert(v);
                for (int nxt : smallGraph[v])
                    if (!vis.count(nxt))
                        dfs(nxt);
            };
            dfs(compList[0]);
            return vis.size() == compList.size();
        };

        if (!connectedSubgraph())
            critical.push_back(i + 1);
    }

    cout << critical.size() << "\n";
    for (auto idx : critical) {
        cout << idx << " ";
    }
    cout << "\n";

    return 0;
}