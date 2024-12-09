#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define vi vector<int>
#define vvi vector<vi>
#define fori(a, b, c) for (int i = a; i < b; i += c)

const int inf = 1e15;
const int ninf = -1e15;
const double EPS = 1e-9;

int get_member(int n, unordered_map<int, int>& cache) {
    if (n <= 1) return n;
    if (cache.find(n) != cache.end()) return cache[n];
    
    int member = 0;
    if (n % 2 == 0) {
        member = get_member(n / 2, cache) + 1;
    } else {
        member = get_member(n + 1, cache) + get_member((n - 1) / 2, cache);
    }
    
    cache[n] = member;
    return member;
}

void run() {
    int n;
    cin >> n;
    unordered_map<int, int> cache;
    cout << get_member(n, cache) << '\n';
    return;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    run();
    return 0;
}