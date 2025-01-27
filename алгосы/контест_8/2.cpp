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

struct DSU {
    vector<int> p;
    DSU(int n) : p(n + 1) { 
        iota(p.begin(), p.end(), 0); 
    }
    int find(int v) {
        return (p[v] == v ? v : p[v] = find(p[v]));
    }
    void unite(int a, int b) {
        p[find(a)] = find(b);
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> edges(n);
    for(int i = 1; i < n; i++){
        cin >> edges[i];
    }

    DSU dsuR(n), dsuB(n); 
    for(int i = 1; i < n; i++){
        for(int j = 0; j < (int)edges[i].size(); j++){
            int to = i + j + 1;
            if(edges[i][j] == 'R'){
                dsuR.unite(i, to);
            } else {
                dsuB.unite(i, to);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            if(dsuR.find(i) == dsuR.find(j) && dsuB.find(i) == dsuB.find(j)){
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
    return 0;
}