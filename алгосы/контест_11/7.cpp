#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    if(N == 1){
        int cost;
        cin >> cost;
        cout << 0 << "\n";
        return 0;
    }
    
    vector<int> fuel(N);
    for (int i = 0; i < N; i++){
        cin >> fuel[i];
    }
    
    int M;
    cin >> M;
    
    vector<vector<int>> adj(N);
    for (int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    const int INF = 1e15;
    vector<int> cost(N, INF);
    cost[0] = 0;
    
    using pii = pair<int,int>;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 0});
    
    while(!pq.empty()){
        auto [currCost, u] = pq.top();
        pq.pop();
        if(currCost != cost[u])
            continue;
        for(auto v : adj[u]){
            int newCost = currCost + fuel[u];
            if(newCost < cost[v]){
                cost[v] = newCost;
                pq.push({newCost, v});
            }
        }
    }
    
    if(cost[N-1] == INF)
        cout << -1 << "\n";
    else
        cout << cost[N-1] << "\n";
    
    return 0;
}