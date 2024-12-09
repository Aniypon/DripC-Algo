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
    int N;
    cin >> N;

    if (N == 1) {
        cout << 2 << endl;
        return;
    }

    vector<int> dpX(N + 1, 0), dpY(N + 1, 0);
    dpX[1] = 1;
    dpY[1] = 1;

    for (int i = 2; i <= N; ++i) {
        dpX[i] = dpX[i - 1] + dpY[i - 1];
        dpY[i] = dpX[i - 1];
    }

    cout << dpX[N] + dpY[N] << endl;
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