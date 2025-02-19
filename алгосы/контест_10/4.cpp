#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1000005;
int parent[MAXN];
int rnk[MAXN];
int sum[MAXN];

void make_set(int v) {
    parent[v] = v;
    rnk[v] = 0;
    sum[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b, int weight) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rnk[a] < rnk[b])
            swap(a, b);
        parent[b] = a;
        sum[a] += sum[b];
        if (rnk[a] == rnk[b])
            rnk[a]++;
    }
    sum[a] += weight;
}

int32_t main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        make_set(i);
    }

    while (m--) {
        int op;
        cin >> op;

        if (op == 1) {
            int x, y, w;
            cin >> x >> y >> w;
            union_sets(x, y, w);
        } else {
            int x;
            cin >> x;
            cout << sum[find_set(x)] << "\n";
        }
    }

    return 0;
}