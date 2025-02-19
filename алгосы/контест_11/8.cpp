#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Edge {
    int to, w;
};

const int INF = 1e15;

vector<int> dijkstra(int start, int n, const vector<vector<Edge>> &graph) {
    vector<int> dist(n, INF);
    dist[start] = 0;
    vector<int> parent(n, -1);
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dist[u])
            continue;
        for (auto edge : graph[u]) {
            int v = edge.to, w = edge.w;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    return parent;
}

vector<int> getPath(int start, int finish, const vector<int> &parent) {
    vector<int> path;
    for (int cur = finish; cur != -1; cur = parent[cur])
        path.push_back(cur);
    reverse(path.begin(), path.end());

    if (path.front() != start)
        path.clear();
    return path;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K, M;
    cin >> N >> K >> M;

    int start = K - 1, dest = N - 1;

    vector<vector<Edge>> graph(N);
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    vector<int> parent1 = dijkstra(start, N, graph);

    vector<int> path1 = getPath(start, dest, parent1);
    if (path1.empty()) {
        cout << -1 << "\n";
        return 0;
    }

    int dist1 = 0;
    for (size_t i = 1; i < path1.size(); i++) {
        int u = path1[i - 1], v = path1[i];
        for (auto edge : graph[u]) {
            if (edge.to == v) {
                dist1 += edge.w;
                break;
            }
        }
    }

    vector<vector<Edge>> graph2 = graph;
    for (size_t i = 1; i < path1.size(); i++) {
        int u = path1[i - 1], v = path1[i];
        auto removeEdge = [&](int from, int to) {
            for (auto it = graph2[from].begin(); it != graph2[from].end(); it++) {
                if (it->to == to) {
                    graph2[from].erase(it);
                    break;
                }
            }
        };
        removeEdge(u, v);
        removeEdge(v, u);
    }

    vector<int> parent2 = dijkstra(dest, N, graph2);
    vector<int> path2 = getPath(dest, start, parent2);
    if (path2.empty()) {
        cout << -1 << "\n";
        return 0;
    }

    int dist2 = 0;
    for (size_t i = 1; i < path2.size(); i++) {
        int u = path2[i - 1], v = path2[i];
        for (auto edge : graph2[u]) {
            if (edge.to == v) {
                dist2 += edge.w;
                break;
            }
        }
    }

    cout << dist1 << " " << dist2 << "\n";
    for (auto u : path1)
        cout << u + 1 << " ";
    cout << "\n";
    for (auto u : path2)
        cout << u + 1 << " ";
    cout << "\n";

    return 0;
}