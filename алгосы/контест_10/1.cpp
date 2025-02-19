#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 150005;
vector<int> graph[MAXN];
bool used[MAXN];
vector<int> result;

void dfs(int v) {
    used[v] = true;
    result.push_back(v);
    
    vector<int> neighbors = graph[v];
    sort(neighbors.begin(), neighbors.end());
    
    for (int u : neighbors) {
        if (!used[u]) {
            dfs(u);
        }
    }
}

int32_t main() {
    int n;
    cin >> n;

    vector<pair<int, int>> edges(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> edges[i].first >> edges[i].second;
    }

    for (int i = n - 2; i >= 0; i--) {
        int u = edges[i].first;
        int v = edges[i].second;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    memset(used, false, sizeof(used));
    
    dfs(3);

    for (int i = 0; i < n; i++) {
        cout << result[i] << (i == n - 1 ? '\n' : ' ');
    }

    return 0;
}