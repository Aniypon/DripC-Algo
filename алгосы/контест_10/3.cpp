#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 100005;
int parent[MAXN];
int rnk[MAXN];
int components;

void make_set(int v) {
    parent[v] = v;
    rnk[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rnk[a] < rnk[b])
            swap(a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b])
            rnk[a]++;
        components--;
    }
}

int32_t main() {
    int n, m;
    cin >> n >> m;
    
    components = n;
    for (int i = 0; i < n; i++) {
        make_set(i);
    }
    
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        union_sets(x, y);
        
        if (components == 1) {
            cout << i << endl;
            return 0;
        }
    }
    
    return 0;
}