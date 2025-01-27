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

int32_t main() {
    int n,m;
    cin >> n >> m;

    vector<int> traf(n+1, 0);

    for(int i =0; i < m;i++){
        int u,v;
        cin >> u >> v;
        traf[u]++;
        traf[v]++;
    }

    for (int i = 1; i <= n; i++){
        cout << traf[i] << " ";
    }

    return 0;
}