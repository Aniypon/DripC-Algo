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
    string s;
    cin >> s;
    int n = s.length();
    
    vi pi(n, 0);
    fori(1, n, 1) {
        int j = pi[i-1];
        while(j > 0 && s[i] != s[j]) {
            j = pi[j-1];
        }
        if(s[i] == s[j]) {
            j++;
        }
        pi[i] = j;
    }
    
    vi borders_count(n, 0);
    fori(0, n, 1) {
        if(pi[i] > 0) {
            borders_count[i] = borders_count[pi[i]-1] + 1;
        }
    }
    
    int max_borders = ninf;
    int answer_length = 1;
    
    fori(0, n, 1) {
        if(borders_count[i] > max_borders) {
            answer_length = i + 1;
            max_borders = borders_count[i];
        }
    }
    
    cout << s.substr(0, answer_length);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    run();
    
    return 0;
}