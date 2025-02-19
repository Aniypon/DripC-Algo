#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 105;
int parent[MAXN];
int rnk[MAXN];

struct Edge {
    int u, v, weight;
    Edge(int u, int v, int w) : u(u), v(v), weight(w) {}
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

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
    }
}

int32_t main() {
    int n, m;
    cin >> n >> m;
    
    vector<Edge> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.emplace_back(u, v, w);
    }
    
    sort(edges.begin(), edges.end());
    
    for (int i = 1; i <= n; i++) {
        make_set(i);
    }
    
    int total_weight = 0;
    for (const Edge& e : edges) {
        if (find_set(e.u) != find_set(e.v)) {
            total_weight += e.weight;
            union_sets(e.u, e.v);
        }
    }
    
    cout << total_weight << endl;
    
    return 0;
}