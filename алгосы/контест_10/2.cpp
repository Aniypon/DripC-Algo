#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 50005;
int parent[MAXN];
int rnk[MAXN];

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
    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].first >> edges[i].second;
    }

    vector<tuple<string, int, int>> operations(k);
    for (int i = 0; i < k; i++) {
        string op;
        int u, v;
        cin >> op >> u >> v;
        operations[i] = {op, u, v};
    }

    for (int i = 1; i <= n; i++) {
        make_set(i);
    }

    map<pair<int, int>, int> edge_index;
    for (int i = 0; i < m; i++) {
        int u = edges[i].first, v = edges[i].second;
        if (u > v)
            swap(u, v);
        edge_index[{u, v}] = i;
    }

    vector<bool> used_edge(m, false);
    vector<string> answers;

    for (int i = k - 1; i >= 0; i--) {
        string op;
        int u, v;
        tie(op, u, v) = operations[i];

        if (op == "cut") {
            if (u > v)
                swap(u, v);
            int idx = edge_index[{u, v}];
            union_sets(u, v);
        } else {
            if (find_set(u) == find_set(v)) {
                answers.push_back("YES");
            } else {
                answers.push_back("NO");
            }
        }
    }

    reverse(answers.begin(), answers.end());
    for (const string& ans : answers) {
        cout << ans << "\n";
    }

    return 0;
}