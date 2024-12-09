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

int calculateDifference(int r, int g, int b) {
    return (r - g) * (r - g) + (g - b) * (g - b) + (r - b) * (r - b);
}

void run() {
    int t;
    cin >> t;
    while (t--) {
        int nr, ng, nb;
        cin >> nr >> ng >> nb;
        vi r(nr), g(ng), b(nb);

        for (int i = 0; i < nr; i++) cin >> r[i];
        for (int i = 0; i < ng; i++) cin >> g[i];
        for (int i = 0; i < nb; i++) cin >> b[i];

        sort(all(r));
        sort(all(g));
        sort(all(b));

        int minDifference = LLONG_MAX;
        int bestR, bestG, bestB;

        auto update = [&](int r, int g, int b) {
            int diff = calculateDifference(r, g, b);
            if (diff < minDifference) {
                minDifference = diff;
                bestR = r;
                bestG = g;
                bestB = b;
            }
        };

        for (int i = 0; i < nr; i++) {
            auto itg = lower_bound(all(g), r[i]);
            auto itb = lower_bound(all(b), r[i]);

            if (itg != g.end() && itb != b.end()) update(r[i], *itg, *itb);
            if (itg != g.end() && itb != b.begin()) update(r[i], *itg, *(--itb));
            if (itg != g.begin() && itb != b.end()) update(r[i], *(--itg), *itb);
            if (itg != g.begin() && itb != b.begin()) update(r[i], *itg, *(--itb));
        }

        for (int i = 0; i < ng; i++) {
            auto itr = lower_bound(all(r), g[i]);
            auto itb = lower_bound(all(b), g[i]);

            if (itr != r.end() && itb != b.end()) update(*itr, g[i], *itb);
            if (itr != r.end() && itb != b.begin()) update(*itr, g[i], *(--itb));
            if (itr != r.begin() && itb != b.end()) update(*(itr - 1), g[i], *itb);
            if (itr != r.begin() && itb != b.begin()) update(*(itr - 1), g[i], *(--itb));
        }

        for (int i = 0; i < nb; i++) {
            auto itr = lower_bound(all(r), b[i]);
            auto itg = lower_bound(all(g), b[i]);

            if (itr != r.end() && itg != g.end()) update(*itr, *itg, b[i]);
            if (itr != r.end() && itg != g.begin()) update(*itr, *(itg - 1), b[i]);
            if (itr != r.begin() && itg != g.end()) update(*(itr - 1), *itg, b[i]);
            if (itr != r.begin() && itg != g.begin()) update(*(itr - 1), *(itg - 1), b[i]);
        }

        cout << bestR << " " << bestG << " " << bestB << endl;
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