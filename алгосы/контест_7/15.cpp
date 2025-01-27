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

const vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

pair<int, int> move(int x, int y, int dx, int dy, vector<vector<int>>& lab) {
    int n = lab.size(), m = lab[0].size();
    while (x >= 0 && x < n && y >= 0 && y < m && lab[x][y] != 1) {
        if (lab[x][y] == 2)
            return {-1, -1};
        x += dx;
        y += dy;
    }
    return {x - dx, y - dy};
}

int32_t main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> lab(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> lab[i][j];
        }
    }

    queue<pair<int, int>> q;
    set<pair<int, int>> visited;
    vector<vector<int>> dist(n, vector<int>(m, -1));

    q.push({0, 0});
    visited.insert({0, 0});
    dist[0][0] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (auto [dx, dy] : dirs) {
            auto [nx, ny] = move(x, y, dx, dy, lab);
            if (nx == -1 && ny == -1) {
                cout << dist[x][y] + 1;
                return 0;
            }
            if (!visited.count({nx, ny})) {
                visited.insert({nx, ny});
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    return 0;
}