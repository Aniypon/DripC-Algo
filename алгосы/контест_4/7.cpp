#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define all(v) v.begin(), v.end()
#define vi vector<int>

const int inf = 1e15;
const int ninf = -1e15;
const double EPS = 1e-9;

void run() {
    int n;
    cin >> n;

    vi a(n), b(n), c(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    vi dp(n + 1, inf);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        dp[i + 1] = min(dp[i + 1], dp[i] + a[i]);

        if (i + 2 <= n) {
            dp[i + 2] = min(dp[i + 2], dp[i] + b[i]);
        }

        if (i + 3 <= n) {
            dp[i + 3] = min(dp[i + 3], dp[i] + c[i]);
        }
    }

    cout << dp[n];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));

    int cnt = 1;
    for (int i = 0; i < cnt; i++) {
        run();
    }
}