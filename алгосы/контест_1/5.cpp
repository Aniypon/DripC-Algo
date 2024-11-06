#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
  int n;
  cin >> n;

  unordered_map<int, int> frequency;

  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    frequency[num]++;
  }

  for (const auto& entry : frequency) {
    if (entry.second == 1 or entry.second == 2) {
      cout << entry.first << " " << entry.second << endl;
      break;
    }
  }

  return 0;
}