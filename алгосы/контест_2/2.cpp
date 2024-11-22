#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
  int x;
  cin >> x;

  int i = 1, j = 1;
  int count = 0;
  int answer = 0;

  while (count < x) {
    int a = i * i;
    int b = j * j * j;

    if (a < b) {
      answer = a;
      i++;
    } else if (a > b) {
      answer = b;
      j++;
    } else {
      answer = a;
      i++;
      j++;
    }
    count++;
  }

  cout << answer << endl;
  return 0;
}