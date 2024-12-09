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

double findMedian(const vi &a, const vi &b) {
    int n = a.size();
    int m = b.size();
    vi merged(n + m);
    merge(all(a), all(b), merged.begin());
    int size = n + m;
    if (size % 2 == 0) {
        return (merged[size / 2 - 1] + merged[size / 2]) / 2.0;
    } else {
        return merged[size / 2];
    }
}

void run() {
    int n, m;
    cin >> n >> m;
    vvi sequences(n, vi(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> sequences[i][j];
        }
    }

    cout << fixed << setprecision(5);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double median = findMedian(sequences[i], sequences[j]);
            cout << median << endl;
        }
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