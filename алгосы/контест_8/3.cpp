#include <bits/stdc++.h>
using namespace std;

static const int INF = 1e9;
const int inf = 1e15;
const int ninf = -1e15;
const double EPS = 1e-9;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, c;
    cin >> r >> c;

    vector<vector<char>> maze(r, vector<char>(c));
    pair<int,int> start, finish;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> noskipws >> maze[i][j];
            if(maze[i][j] == '\n') { 
                j--; 
                continue; 
            }
            if(maze[i][j] == 'S'){
                start = {i, j};
            }
            if(maze[i][j] == 'F'){
                finish = {i, j};
            }
        }
    }

    vector<vector<vector<int>>> dist(r, vector<vector<int>>(c, vector<int>(4, INF)));
    
    queue<array<int,3>>q;
    
    for(int d = 0; d < 4; d++){
        dist[start.first][start.second][d] = 0;
        q.push({start.first, start.second, d});
    }

    while(!q.empty()){
        auto [rr, cc, dd] = q.front();
        q.pop();
        int currDist = dist[rr][cc][dd];
        
        if(make_pair(rr, cc) == finish){
            cout << currDist << "\n";
            return 0;
        }
        
        int nr = rr + dr[dd];
        int nc = cc + dc[dd];
        if(maze[nr][nc] != 'X' && dist[nr][nc][dd] > currDist + 1){
            dist[nr][nc][dd] = currDist + 1;
            q.push({nr, nc, dd});
        }
        
        int nd = (dd + 1) % 4;
        nr = rr + dr[nd];
        nc = cc + dc[nd];
        if(maze[nr][nc] != 'X' && dist[nr][nc][nd] > currDist + 1){
            dist[nr][nc][nd] = currDist + 1;
            q.push({nr, nc, nd});
        }
    }

    cout << "0\n";
    return 0;
}