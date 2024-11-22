#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define pb push_back
#define pii pair<int,int>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define vi vector<int>
#define vvi vector<vi>
#define fori(a , b , c) for(int i = a; i < b; i+= c)

const int inf = 1e15;
const int ninf = -1e15;
const double EPS = 1e-9;

void run() {
    long long n, k;
    cin >> n >> k;

    auto count = [&](long long x) {
        long long cnt = 0;
        long long k_power = k;
        for (int l = 1; k_power <= x; l += 2) {
            long long m_max = x / k_power;
            cnt += m_max - m_max / k;
            if (k_power > x / (k * k)) break;
            k_power *= k * k;
        }
        return cnt;
    };

    long long left = 1, right = 1e18, ans = -1;
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (count(mid) >= n) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int cnt = 1;
    for(int i = 0; i < cnt; i++){
        run();
    }
}