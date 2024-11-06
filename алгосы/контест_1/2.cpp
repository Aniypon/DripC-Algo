#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  long long A, B, C;
  cin >> A >> B >> C;

  long long cycles = min({A, B / 2, C});
  long long total_time = cycles * 4;

  A -= cycles;
  B -= cycles * 2;
  C -= cycles;

  while (true) {
    if (A > 0) {
      A--;
      total_time++;
    } else {
      break;
    }

    if (B > 0) {
      B--;
      total_time++;
    } else {
      break;
    }

    if (C > 0) {
      C--;
      total_time++;
    } else {
      break;
    }

    if (B > 0) {
      B--;
      total_time++;
    } else {
      break;
    }
  }

  cout << total_time << endl;

  return 0;
}