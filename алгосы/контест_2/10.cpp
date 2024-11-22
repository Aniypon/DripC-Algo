#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define pb push_back
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define vi vector<int>
#define vvi vector<vi>
#define fori(a, b, c) for (int i = a; i < b; i += c)

const int inf = 1e15;
const int ninf = -1e15;
const double EPS = 1e-9;

void run() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }

  vector<vector<int>> dp(n, vector<int>(m));
  int max_side = 0;

  for (int i = 0; i < n; i++) {
    dp[i][0] = a[i][0];
    max_side = max(max_side, dp[i][0]);
  }
  for (int j = 0; j < m; j++) {
    dp[0][j] = a[0][j];
    max_side = max(max_side, dp[0][j]);
  }

  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      if (a[i][j] == 1) {
        dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
        max_side = max(max_side, dp[i][j]);
      }
    }
  }

  cout << max_side << "\n";
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int cnt = 1;
  for (int i = 0; i < cnt; i++) {
    run();
  }
}