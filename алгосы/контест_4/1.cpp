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

const int inf = 1e15;
const int ninf = -1e15;
const double EPS = 1e-9;

int countSteps(int n) {
  if (n < 0)
    return 0;
  if (n == 0)
    return 1;

  vi dp(n + 1, 0);
  dp[0] = 1;

  for (int i = 1; i <= n; ++i) {
    if (i >= 1)
      dp[i] += dp[i - 1];
    if (i >= 2)
      dp[i] += dp[i - 2];
    if (i >= 3)
      dp[i] += dp[i - 3];
  }

  return dp[n];
}

void run() {
  int n;
  cin >> n;
  cout << countSteps(n);
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
}