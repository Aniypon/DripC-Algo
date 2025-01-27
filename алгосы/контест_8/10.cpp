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

vector<pair<int,int>> bridges;
vector<vector<int>> g;
vector<bool> used;
vector<int> tin, fup;
int timer = 0;

void dfs(int v, int p = -1) {
    used[v] = true;
    tin[v] = fup[v] = timer++;
    for(auto &to : g[v]) {
        if(to == p) continue;
        if(used[to]) {
            fup[v] = min(fup[v], tin[to]);
        } else {
            dfs(to, v);
            fup[v] = min(fup[v], fup[to]);
            if(fup[to] > tin[v]) {
                if(to > v) {
                    bridges.pb({v, to});
                } else {
                    bridges.pb({to, v});
                }
            }
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    g.resize(n);
    map<pair<int,int>, int> edge_num;

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; 
        v--;
        g[u].pb(v);
        g[v].pb(u);
        if(u > v) swap(u, v);
        edge_num[{u, v}] = i + 1;
    }

    used.assign(n, false);
    tin.resize(n);
    fup.resize(n);

    for(int i = 0; i < n; i++) {
        if(!used[i]) dfs(i);
    }

    vector<int> ans;
    for(auto &b : bridges) {
        ans.pb(edge_num[b]);
    }
    sort(all(ans));

    cout << ans.size() << '\n';
    for(int i : ans) {
        cout << i << '\n';
    }

    return 0;
}