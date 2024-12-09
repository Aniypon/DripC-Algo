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
  int n;
  cin >> n;
  vi cost(n);
  for (int i = 0; i < n; i++) {
    cin >> cost[i];
  }

  if (n == 1) {
    cout << cost[0] << endl;
    return;
  }

  vi dp(n);
  dp[0] = cost[0];
  dp[1] = min(cost[0] + cost[1], cost[1]);

  for (int i = 2; i < n; i++) {
    dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
  }

  cout << dp[n-1] << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  srand(time(0));

  int cnt = 1;
  for (int i = 0; i < cnt; i++) {
    run();
  }

  return 0;
}