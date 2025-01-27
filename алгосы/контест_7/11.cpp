#include <bits/stdc++.h>
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

const vector<pair<int, int>> moves = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

bool valid(int x, int y, int n) {
    return x >= 1 && x <= n && y >= 1 && y <= n;
}

int32_t main() {
    int n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;

    vector<vector<int>> dist(n + 1, vector<int>(n + 1, -1));
    vector<vector<pair<int, int>>> parent(n + 1, vector<pair<int, int>>(n + 1));
    queue<pair<int, int>> q;

    dist[x1][y1] = 0;
    q.push({x1, y1});

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (x == x2 && y == y2)
            break;

        for (auto [dx, dy] : moves) {
            int nx = x + dx, ny = y + dy;
            if (valid(nx, ny, n) && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                parent[nx][ny] = {x, y};
                q.push({nx, ny});
            }
        }
    }

    cout << dist[x2][y2] << endl;

    vector<pair<int, int>> path;
    for (int x = x2, y = y2; x != x1 || y != y1;) {
        path.push_back({x, y});
        auto [px, py] = parent[x][y];
        x = px;
        y = py;
    }
    path.push_back({x1, y1});

    reverse(path.begin(), path.end());
    for (auto [x, y] : path) {
        cout << x << " " << y << endl;
    }

    return 0;
}