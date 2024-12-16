#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define vi vector<int>

const int inf = 1e15;
const int ninf = -1e15;
const double EPS = 1e-9;

void run() {
    string alpha, beta;
    cin >> alpha >> beta;
    int n = alpha.size();
    int m = beta.size();
    vi pi(m, 0);
    for (int i = 1; i < m; ++i) {
        int j = pi[i - 1];
        while (j > 0 && beta[i] != beta[j])
            j = pi[j - 1];
        if (beta[i] == beta[j])
            ++j;
        pi[i] = j;
    }
    vi positions;
    int j = 0;
    for (int i = 0; i < n; ++i) {
        while (j > 0 && alpha[i] != beta[j])
            j = pi[j - 1];
        if (alpha[i] == beta[j])
            ++j;
        if (j == m) {
            positions.push_back(i - m + 2);
            j = pi[j - 1];
        }
    }
    cout << positions.size() << endl;
    for (int pos : positions) {
        cout << pos << " ";
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    run();
    return 0;
}