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

bool bfsCheck(vector<vector<int>>& graph, vector<int>& color, int start) {
    queue<int> q;
    color[start] = 0;
    q.push(start);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int neigh : graph[node]){
            if(color[neigh] == -1){
                color[neigh] = 1 - color[node];
                q.push(neigh);
            } else if(color[neigh] == color[node]){
                return false; 
            }
        }
    }
    return true;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N + 1);
    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    vector<int> color(N + 1, -1);
    for(int i = 1; i <= N; i++){
        if(color[i] == -1){
            if(!bfsCheck(graph, color, i)){
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
    return 0;
}