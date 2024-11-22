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

struct StrWithIndex {
  string str;
  int index;
};

bool compareByLength(const StrWithIndex& a, const StrWithIndex& b) {
  if (a.str.length() == b.str.length())
    return a.index < b.index;
  return a.str.length() < b.str.length();
}

void run() {
  int n;
  cin >> n;
  cin.ignore();
  
  vector<StrWithIndex> strings(n);
  for (int i = 0; i < n; i++) {
    getline(cin, strings[i].str);
    strings[i].index = i;
  }

  stable_sort(strings.begin(), strings.end(), compareByLength);

  for (const auto& s : strings) {
    cout << s.str << "\n";
  }
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