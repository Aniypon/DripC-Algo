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

int timer = 0;
vector<int> tin, low;
vector<bool> onStack;
stack<int> st;
int sccCount = 0;
vector<int> comp;
vector<vector<int>> sccNodes;

void tarjan_dfs(int v, const vector<vector<int>> &g) {
    tin[v] = low[v] = ++timer;
    st.push(v);
    onStack[v] = true;
    for (int to : g[v]) {
        if (tin[to] == 0) {
            tarjan_dfs(to, g);
            low[v] = min(low[v], low[to]);
        } else if (onStack[to]) {
            low[v] = min(low[v], tin[to]);
        }
    }
    if (low[v] == tin[v]) {
        vector<int> compGroup;
        while (true) {
            int cur = st.top();
            st.pop();
            onStack[cur] = false;
            comp[cur] = sccCount;
            compGroup.pb(cur);
            if (cur == v)
                break;
        }
        sccNodes.pb(compGroup);
        sccCount++;
    }
}

bool dfsReach(int cur, int target, const vector<vector<int>> &dag, vector<bool> &used) {
    if (cur == target)
        return true;
    used[cur] = true;
    for (auto nxt : dag[cur]) {
        if (!used[nxt] && dfsReach(nxt, target, dag, used))
            return true;
    }
    return false;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    vector<tuple<int, int>> origEdges;
    vector<pair<int, pair<int, int>>> interCandidates;

    vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
        origEdges.push_back({u, v});
        edges.push_back({u, v});
    }

    tin.assign(n + 1, 0);
    low.assign(n + 1, 0);
    onStack.assign(n + 1, false);
    comp.assign(n + 1, -1);

    for (int i = 1; i <= n; i++) {
        if (tin[i] == 0)
            tarjan_dfs(i, graph);
    }

    vector<pair<int, int>> intraFlights;
    for (auto &group : sccNodes) {
        if (group.size() > 1) {
            for (size_t i = 0; i < group.size() - 1; i++) {
                intraFlights.push_back({group[i], group[i + 1]});
            }
            intraFlights.push_back({group.back(), group[0]});
        }
    }

    int compN = sccCount;
    vector<unordered_map<int, pair<int, int>>> condEdges(compN);
    for (auto &e : origEdges) {
        int u, v;
        tie(u, v) = e;
        int cu = comp[u], cv = comp[v];
        if (cu != cv) {
            if (condEdges[cu].find(cv) == condEdges[cu].end()) {
                condEdges[cu][cv] = {u, v};
            }
        }
    }

    vector<vector<int>> dag(compN);
    for (int u = 0; u < compN; u++) {
        for (auto &entry : condEdges[u]) {
            int v = entry.first;
            dag[u].push_back(v);
        }
    }

    vector<pair<int, int>> interFlights;
    for (int u = 0; u < compN; u++) {
        for (auto &entry : condEdges[u]) {
            int v = entry.first;
            bool redundant = false;
            for (auto &other : condEdges[u]) {
                int w = other.first;
                if (w == v)
                    continue;
                vector<bool> used(compN, false);
                if (dfsReach(w, v, dag, used)) {
                    redundant = true;
                    break;
                }
            }
            if (!redundant) {
                interFlights.push_back(condEdges[u][v]);
            }
        }
    }

    vector<pair<int, int>> res;
    for (auto &e : intraFlights)
        res.push_back(e);
    for (auto &e : interFlights)
        res.push_back(e);

    cout << res.size() << "\n";
    for (auto &e : res)
        cout << e.first << " " << e.second << "\n";

    return 0;
}