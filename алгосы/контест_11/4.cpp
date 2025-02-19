#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, S, F;
    cin >> N >> S >> F;
    
    vector<vector<int>> graph(N, vector<int>(N));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> graph[i][j];
        }
    }
    
    const int INF = 1e18;
    vector<int> dist(N, INF);
    vector<int> parent(N, -1);
    vector<bool> visited(N, false);
    
    dist[S-1] = 0;
    
    for(int i = 0; i < N; i++){
        int v = -1;
        for(int j = 0; j < N; j++){
            if(!visited[j] && (v == -1 || dist[j] < dist[v])){
                v = j;
            }
        }
        if(v == -1) break;
        visited[v] = true;
        
        for(int u = 0; u < N; u++){
            if(graph[v][u] != -1){
                if(dist[v] + graph[v][u] < dist[u]){
                    dist[u] = dist[v] + graph[v][u];
                    parent[u] = v;
                }
            }
        }
    }
    
    if(dist[F-1] == INF){
        cout << -1;
        return 0;
    }
    
    vector<int> path;
    for(int cur = F-1; cur != -1; cur = parent[cur]){
        path.push_back(cur);
    }
    reverse(path.begin(), path.end());
    
    for(size_t i = 0; i < path.size(); i++){
        cout << path[i] + 1 << (i+1 < path.size() ? " " : "");
    }
    
    return 0;
}