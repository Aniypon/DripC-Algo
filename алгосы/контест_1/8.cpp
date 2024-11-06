#include <bits/stdc++.h>
using namespace std;
#define int long long

int findNthDigit(int n) {
  long long length = 1;
  long long count = 9;
  long long start = 1;

  while (n > length * count) {
    n -= length * count;
    length++;
    count *= 10;
    start *= 10;
  }

  start += (n - 1) / length;
  string s = to_string(start);

  return s[(n - 1) % length] - '0';
}

int32_t main() {
  int n;
  cin >> n;
  cout << findNthDigit(n) << endl;
  return 0;
}
