#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;

int32_t main(){
    int n, s, f;
    cin >> n >> s >> f;
    s--; f--;
    
    vector<vector<int>> graph(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> graph[i][j];
        }
    }
    
    vector<int> dist(n, INF);
    vector<bool> used(n, false);
    dist[s] = 0;
    
    for(int i = 0; i < n; i++){
        int v = -1;
        for(int j = 0; j < n; j++){
            if(!used[j] && (v == -1 || dist[j] < dist[v])){
                v = j;
            }
        }
        
        if(dist[v] == INF) break;
        used[v] = true;
        
        for(int u = 0; u < n; u++){
            if(graph[v][u] != -1){
                if(dist[v] + graph[v][u] < dist[u]){
                    dist[u] = dist[v] + graph[v][u];
                }
            }
        }
    }
    
    cout << (dist[f] == INF ? -1 : dist[f]) << endl;
    
    return 0;
}