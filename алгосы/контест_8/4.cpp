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
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N + 1);
    vector<int> inDegree(N + 1, 0);

    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        inDegree[B]++;
    }

    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (!inDegree[i])
            q.push(i);
    }

    vector<int> order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (int v : adj[u]) {
            if (--inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    if ((int)order.size() < N) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
        for (int i = 0; i < N; i++) {
            cout << order[i] << (i + 1 < N ? ' ' : '\n');
        }
    }
    return 0;
}