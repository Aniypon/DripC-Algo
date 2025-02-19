#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    int S, E;
    cin >> S >> E;
    S--;
    E--;

    vector<vector<pair<int, double>>> graph(N);
    for (int i = 0; i < M; i++) {
        int u, v, p;
        cin >> u >> v >> p;
        u--;
        v--;
        double probSafe = 1.0 - (p / 100.0);
        double weight = (probSafe > 0 ? -log(probSafe) : numeric_limits<double>::infinity());

        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight});
    }

    vector<double> dist(N, numeric_limits<double>::infinity());
    dist[S] = 0.0;
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    pq.push({0.0, S});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u])
            continue;
        for (auto &edge : graph[u]) {
            int v = edge.first;
            double w = edge.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    double d = dist[E];
    double risk = 1.0 - exp(-d);

    cout << fixed << setprecision(10) << risk << "\n";

    return 0;
}