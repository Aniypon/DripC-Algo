#include <bits/stdc++.h>
using namespace std;

#define int long long

int search(vector<int>& nums, int target) {
  int l = 0, r = nums.size() - 1;

  while (l <= r) {
    int m = l + (r - l) / 2;
    if (nums[m] == target)
      return m;

    if (nums[l] <= nums[m]) {
      if (nums[l] <= target and target <= nums[m]) {
        r = m - 1;
      } else {
        l = m + 1;
      }
    } else if (nums[m] <= target and target <= nums[r]) {
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  return -1;
}

int32_t main() {
  int n, target;
  cin >> n;
  vector<int> arr(n);

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  cin >> target;

  cout << search(arr, target) << endl;
  return 0;
}
