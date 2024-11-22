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

double fastPow(double a, int n) {
  if (n == 0)
    return 1;
  if (n < 0) {
    return 1.0 / fastPow(a, -n);
  }

  if (n % 2 == 0) {
    double half = fastPow(a, n / 2);
    return half * half;
  } else {
    return a * fastPow(a, n - 1);
  }
}

void run() {
  double a;
  int n;
  cin >> a >> n;
  cout << fixed << setprecision(7) << fastPow(a, n) << "\n";
  return;
  return;
}

signed main() { 
  // freopen("input.txt", "r", stdin);

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  srand(time(0));

  int cnt = 1;
  // cin >> cnt;

  for (int i = 0; i < cnt; i++) {
    run();
  }
}