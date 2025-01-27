#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

struct Train {
    int A, B, C, D;
};

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; 
    cin >> N;
    vector<Train> trains(N);
    for(int i=0; i<N; i++){
        cin >> trains[i].A >> trains[i].B >> trains[i].C >> trains[i].D;
    }

    vector<vector<int>> adj(N);
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            int left = max(trains[i].A, trains[j].A);
            int right = min(trains[i].B, trains[j].B);
            if(left <= right) {
                int ti = trains[i].C + (left - trains[i].A)*trains[i].D;
                int tj = trains[j].C + (left - trains[j].A)*trains[j].D;
                if(ti < tj) {
                    adj[i].pb(j);
                } else {
                    adj[j].pb(i);
                }
            }
        }
    }

    vector<int> inDegree(N, 0);
    for(int i=0; i<N; i++){
        for(int v : adj[i]){
            inDegree[v]++;
        }
    }

    queue<int> q;
    for(int i=0; i<N; i++){
        if(inDegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> order;
    while(!q.empty()){
        int u = q.front(); 
        q.pop();
        order.pb(u);
        for(int nxt : adj[u]) {
            if(--inDegree[nxt] == 0){
                q.push(nxt);
            }
        }
    }

    for(int x : order){
        cout << x+1 << " ";
    }
    cout << "\n";
    return 0;
}