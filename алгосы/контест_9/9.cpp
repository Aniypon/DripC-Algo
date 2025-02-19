#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> names;
vector<vector<int>> graph;
vector<bool> visited;
vector<int> result;

void dfs(int u) {
    visited[u] = true;
    result.push_back(u);
    for (int v : graph[u]) {
        if (!visited[v])
            dfs(v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    names.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        int idx;
        cin >> idx;
        getline(cin, names[idx]);
        if (!names[idx].empty() && names[idx][0] == ' ')
            names[idx].erase(0, 1);
    }

    graph.assign(n + 1, vector<int>());
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end(), [&](int a, int b) { return names[a] < names[b]; });
    }

    visited.assign(n + 1, false);

    vector<pair<string, int>> order;
    for (int i = 1; i <= n; i++) {
        order.push_back({names[i], i});
    }
    sort(order.begin(), order.end());

    for (auto &p : order) {
        int i = p.second;
        if (!visited[i])
            dfs(i);
    }

    for (int idx : result)
        cout << names[idx] << "\n";

    return 0;
}