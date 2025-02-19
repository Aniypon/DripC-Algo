#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e18;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K, S, F;
    cin >> N >> M >> K >> S >> F;
    S--;
    F--;

    vector<tuple<int, int, int>> flights;
    for (int i = 0; i < M; i++) {
        int u, v, p;
        cin >> u >> v >> p;
        u--;
        v--;
        flights.push_back({u, v, p});
    }

    vector<vector<int>> dp(K + 1, vector<int>(N, INF));
    dp[0][S] = 0;

    for (int i = 0; i < K; i++) {
        for (int u = 0; u < N; u++) {
            dp[i + 1][u] = min(dp[i + 1][u], dp[i][u]);
        }
        for (auto [u, v, p] : flights) {
            if (dp[i][u] != INF) {
                dp[i + 1][v] = min(dp[i + 1][v], dp[i][u] + p);
            }
        }
    }

    int ans = INF;
    for (int i = 1; i <= K; i++) {
        ans = min(ans, dp[i][F]);
    }

    cout << (ans == INF ? -1 : ans) << "\n";
    return 0;
}