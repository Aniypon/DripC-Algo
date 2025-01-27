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

    vector<vector<int>> dist(n, vector<int>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    int minL = inf;
    vector<int> res(3);

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int k = j + 1; k < n; k++){
                int curL = dist[i][j] + dist[j][k] + dist[k][i];
                if (curL < minL){
                    minL = curL;
                    res = {i+1, j+1, k+1};
                }
            }
        }
    }

    cout << res[0] << " " << res[1] << " " << res[2];

    return 0;
}