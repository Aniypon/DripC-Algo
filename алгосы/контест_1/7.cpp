#include <bits/stdc++.h>
using namespace std;
#define int long long

int singleNonDuplicate(vector<int>& nums) {
  int l = 0, r = nums.size() - 1;
  while (l < r) {
    int m = l + (r - l) / 2;
    if (m % 2 == 1) {
      m--;
    }
    if (nums[m] != nums[m + 1]) {
      r = m;
    } else {
      l = m + 2;
    }
  }
  return nums[l];
}

int32_t main(){
  int n;
  cin >> n;
  vector<int> arr(n);

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  cout << singleNonDuplicate(arr) << endl;
  return 0;
}
