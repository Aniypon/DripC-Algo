#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    const int INF = 1e15;
    vector<vector<int>> dist(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    const int NEG_INF = -1e15;
    for (int k = 0; k < n; k++) {
        if (dist[k][k] < 0) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] != INF && dist[k][j] != INF) {
                        dist[i][j] = NEG_INF;
                    }
                }
            }
        }
    }

    int ans = INF;
    bool negativeCycleFound = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;
            if (dist[i][j] == NEG_INF) {
                negativeCycleFound = true;
                break;
            }
            ans = min(ans, dist[i][j]);
        }
        if (negativeCycleFound)
            break;
    }

    if (negativeCycleFound)
        cout << -1 << "\n";
    else
        cout << ans << "\n";

    return 0;
}