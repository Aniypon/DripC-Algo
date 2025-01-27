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

void dfs(int v, vector<vector<int>>& adj, set<int>& component) {
    component.insert(v);
    for(int u : adj[v]) {
        if(component.find(u) == component.end()) {
            dfs(u, adj, component);
        }
    }
}

int32_t main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    set<int> component;
    dfs(0, adj, component);
    
    cout << component.size() << endl;
    for(int v : component) {
        cout << v + 1 << " ";
    }
    
    return 0;
}