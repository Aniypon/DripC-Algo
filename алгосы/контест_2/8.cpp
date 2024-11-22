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

  vector<int> max_press(n);
  for (int i = 0; i < n; i++) {
    cin >> max_press[i];
  }

  int k;
  cin >> k;

  vector<int> actual_press(n, 0);
  for (int i = 0; i < k; i++) {
    int key;
    cin >> key;
    key--;  
    actual_press[key]++;
  }

  for (int i = 0; i < n; i++) {
    if (actual_press[i] > max_press[i]) {
      cout << "yes\n";
    } else {
      cout << "no\n";
    }
  }
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