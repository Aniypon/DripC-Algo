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
        cout << 3 << endl; 
        return;
    }

    vector<int> dpA(N + 1, 0), dpB(N + 1, 0), dpC(N + 1, 0);
    dpA[1] = 1;
    dpB[1] = 1;
    dpC[1] = 1;

    for (int i = 2; i <= N; ++i) {
        dpA[i] = dpB[i - 1] + dpC[i - 1];
        dpB[i] = dpA[i - 1] + dpB[i - 1] + dpC[i - 1];
        dpC[i] = dpA[i - 1] + dpB[i - 1] + dpC[i - 1];
    }

    cout << dpA[N] + dpB[N] + dpC[N] << endl;
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