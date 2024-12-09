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

    vi nominal(n);
    for (int i = 0; i < n; i++) {
        cin >> nominal[i];
    }

    int target;
    cin >> target;

    vi dp(target + 1, inf);
    vi prev(target + 1, -1);

    dp[0] = 0;

    for (int sum = 1; sum <= target; sum++) {
        for (int j = 0; j < n; j++) {
            if (sum >= nominal[j] && dp[sum - nominal[j]] != inf) {
                if (dp[sum] > dp[sum - nominal[j]] + 1) {
                    dp[sum] = dp[sum - nominal[j]] + 1;
                    prev[sum] = nominal[j];
                }
            }
        }
    }

    if (dp[target] == inf) {
        cout << -1 << "\n";
        return;
    }

    cout << dp[target] << "\n";

    int current = target;
    while (current > 0) {
        cout << prev[current] << " ";
        current -= prev[current];
    }
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