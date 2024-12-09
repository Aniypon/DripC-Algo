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

void run() {
    int n;
    cin >> n;

    vector<int> dp(n + 1, inf);
    vector<int> prev(n + 1, -1);
    dp[1] = 0;

    for (int i = 1; i < n; ++i) {
        if (i * 2 <= n && dp[i * 2] > dp[i] + 1) {
            dp[i * 2] = dp[i] + 1;
            prev[i * 2] = i;
        }
        if (i * 3 <= n && dp[i * 3] > dp[i] + 1) {
            dp[i * 3] = dp[i] + 1;
            prev[i * 3] = i;
        }
        if (i + 1 <= n && dp[i + 1] > dp[i] + 1) {
            dp[i + 1] = dp[i] + 1;
            prev[i + 1] = i;
        }
    }

    cout << dp[n] << endl;

    vector<int> path;
    for (int i = n; i != -1; i = prev[i]) {
        path.pb(i);
    }
    reverse(all(path));

    for (int x : path) {
        cout << x << " ";
    }
    cout << endl;
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