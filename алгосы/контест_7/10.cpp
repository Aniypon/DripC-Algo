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
    int n;
    cin >> n;

    vector<vector<int>> adj(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }

    int start, end;
    cin >> start >> end;
    start--;
    end--; 

    vector<int> dist(n, -1);
    vector<int> parent(n, -1);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int u = 0; u < n; u++) {
            if (adj[v][u] && dist[u] == -1) {
                dist[u] = dist[v] + 1;
                parent[u] = v;
                q.push(u);
            }
        }
    }

    if (dist[end] == -1) {
        cout << -1;
        return 0;
    }

    cout << dist[end] << endl;
    if (dist[end] > 0) {
        vector<int> path;
        for (int v = end; v != -1; v = parent[v]) {
            path.push_back(v + 1);
        }
        reverse(path.begin(), path.end());

        for (int v : path) {
            cout << v << " ";
        }
    }

    return 0;
}