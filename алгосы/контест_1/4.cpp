#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
  int n;
  cin >> n;
  vector<int> arr(n);

  int xor_all = 0;
  int xor_arr = 0;

  for (int i = 0; i < n; ++i) {
    std::cin >> arr[i];
    xor_arr ^= arr[i];
  }

  for (int i = 1; i <= n + 1; ++i) {
    xor_all ^= i;
  }

  int missing_number = xor_all ^ xor_arr;

  cout << missing_number << std::endl;
  return 0;
}