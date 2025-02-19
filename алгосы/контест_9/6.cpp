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

int timer;
vector<int> tin, low;
vector<bool> articulation;

void dfs(int v, int parent, const vector<vector<int>> &g) {
    tin[v] = low[v] = ++timer;
    int children = 0;
    for (auto to : g[v]) {
        if (to == parent)
            continue;
        if (tin[to] != -1) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v, g);
            low[v] = min(low[v], low[to]);
            if (parent != -1 && low[to] >= tin[v])
                articulation[v] = true;
            children++;
        }
    }
    if (parent == -1 && children > 1)
        articulation[v] = true;
}

int32_t main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    timer = 0;
    tin.assign(n + 1, -1);
    low.assign(n + 1, -1);
    articulation.assign(n + 1, false);
    
    for (int i = 1; i <= n; i++){
        if(tin[i] == -1)
            dfs(i, -1, g);
    }
    
    vector<int> ans;
    for (int i = 1; i <= n; i++){
        if(articulation[i])
            ans.push_back(i);
    }
    sort(ans.begin(), ans.end());
    
    cout << ans.size() << "\n";
    for(auto x : ans)
        cout << x << " ";
    cout << "\n";
    
    return 0;
}