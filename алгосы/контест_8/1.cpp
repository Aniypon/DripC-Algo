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

bool isBipartite(vector<vector<int>>& graph, int n, vector<int>& color) {
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (color[i] == -1) {
            color[i] = 0;
            q.push(i);
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : graph[u]) {
                    if (color[v] == -1) {
                        color[v] = 1 - color[u];
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int32_t main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> color(n + 1, -1);
    if (isBipartite(graph, n, color)) {
        cout << "YES" << endl;
        vector<int> day1, day2;
        for (int i = 1; i <= n; ++i) {
            if (color[i] == 0) {
                day1.push_back(i);
            } else {
                day2.push_back(i);
            }
        }
        if (day1.size() <= day2.size()) {
            cout << day1.size() << endl;
            for (int exam : day1) {
                cout << exam << " ";
            }
        } else {
            cout << day2.size() << endl;
            for (int exam : day2) {
                cout << exam << " ";
            }
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
}