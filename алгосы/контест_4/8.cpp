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
    
    vector<vector<double>> rates(n, vector<double>(2));
    for (int i = 0; i < n; i++) {
        cin >> rates[i][0] >> rates[i][1];
    }
    
    vector<vector<double>> dp(n + 1, vector<double>(3));
    dp[0][0] = 100; 
    dp[0][1] = dp[0][2] = 0;
    
    for (int day = 0; day < n; day++) {
        double usd_rate = rates[day][0];
        double eur_rate = rates[day][1];
        
        for (int to = 0; to < 3; to++) {
            dp[day + 1][to] = 0;
            if (to == 0) dp[day + 1][to] = max(dp[day + 1][to], dp[day][0]);
            if (to == 1) dp[day + 1][to] = max(dp[day + 1][to], dp[day][0] / usd_rate);
            if (to == 2) dp[day + 1][to] = max(dp[day + 1][to], dp[day][0] / eur_rate);
            
            if (to == 0) dp[day + 1][to] = max(dp[day + 1][to], dp[day][1] * usd_rate);
            if (to == 1) dp[day + 1][to] = max(dp[day + 1][to], dp[day][1]);
            if (to == 2) dp[day + 1][to] = max(dp[day + 1][to], dp[day][1] * usd_rate / eur_rate);
            
            if (to == 0) dp[day + 1][to] = max(dp[day + 1][to], dp[day][2] * eur_rate);
            if (to == 1) dp[day + 1][to] = max(dp[day + 1][to], dp[day][2] * eur_rate / usd_rate);
            if (to == 2) dp[day + 1][to] = max(dp[day + 1][to], dp[day][2]);
        }
    }
    
    cout << fixed << setprecision(2) << dp[n][0] << "\n";
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