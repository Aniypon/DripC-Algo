#include <bits/stdc++.h>
using namespace std;

int n, k;

int countNotGreaterThanMid(const vector<vector<int>>& matrix, int m) {
  int count = 0;
  int j = n - 1;
  for (int i = 0; i < n; ++i) {
    while (j >= 0 && matrix[i][j] > m) {
      --j;
    }
    count += (j + 1);
  }
  return count;
}

int main() {
  cin >> n >> k;
  vector<vector<int>> matrix(n, vector<int>(n));

  int min_val = INT_MAX;
  int max_val = INT_MIN;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> matrix[i][j];
      min_val = min(min_val, matrix[i][j]);
      max_val = max(max_val, matrix[i][j]);
    }
  }

  int l = min_val;
  int r = max_val;
  int result = min_val;

  while (l <= r) {
    int m = l + (r - l) / 2;
    int count = countNotGreaterThanMid(matrix, m);

    if (count < k) {
      l = m + 1;
    } else {
      result = m;
      r = m - 1;
    }
  }

  cout << result << endl;
  return 0;
}