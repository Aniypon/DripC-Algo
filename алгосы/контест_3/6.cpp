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
    int x;
    cin >> x;

    int i = 1, j = 1;
    int count = 0;
    int result = 0;

    while (count < x) {
        int a = i * i;
        int b = j * j * j;

        if (a < b) {
            result = a;
            i++;
        } else if (a > b) {
            result = b;
            j++;
        } else {
            result = a;
            i++;
            j++;
        }

        count++;
    }

    cout << result << endl;
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