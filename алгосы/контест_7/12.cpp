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

bool valid(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

pair<int, int> convert(string pos) {
    return {pos[0] - 'a', pos[1] - '1'};
}

int32_t main() {
    string pos1, pos2;
    cin >> pos1 >> pos2;

    auto [x1, y1] = convert(pos1);
    auto [x2, y2] = convert(pos2);

    vector<vector<vector<vector<int>>>> dist(
        8, vector<vector<vector<int>>>(8, vector<vector<int>>(8, vector<int>(8, -1))));

    queue<tuple<int, int, int, int>> q;
    q.push({x1, y1, x2, y2});
    dist[x1][y1][x2][y2] = 0;

    while (!q.empty()) {
        auto [rx, ry, gx, gy] = q.front();
        q.pop();

        if (rx == gx && ry == gy) {
            cout << dist[rx][ry][gx][gy];
            return 0;
        }

        for (auto [dx1, dy1] : moves) {
            for (auto [dx2, dy2] : moves) {
                int nrx = rx + dx1, nry = ry + dy1;
                int ngx = gx + dx2, ngy = gy + dy2;

                if (valid(nrx, nry) && valid(ngx, ngy) && dist[nrx][nry][ngx][ngy] == -1) {
                    dist[nrx][nry][ngx][ngy] = dist[rx][ry][gx][gy] + 1;
                    q.push({nrx, nry, ngx, ngy});
                }
            }
        }
    }

    cout << -1;
    return 0;
}