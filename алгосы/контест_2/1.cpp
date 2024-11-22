#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> l(n), r(n);
  for (int i = 0; i < n; ++i) {
    cin >> l[i] >> r[i];
  }

  vector<int> x(m);
  for (int i = 0; i < m; ++i) {
    cin >> x[i];
  }

  sort(l.begin(), l.end());
  sort(r.begin(), r.end());

  for (int i = 0; i < m; ++i) {
    int starts = upper_bound(l.begin(), l.end(), x[i]) - l.begin();
    int ends = lower_bound(r.begin(), r.end(), x[i]) - r.begin();
    cout << starts - ends << " ";
  }
  cout << endl;

  return 0;
}