#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

const int inf = 1e15;
const int ninf = -1e15;
const double EPS = 1e-9;

vector<int> z_function(string s) {
    int n = s.length();
    vector<int> z(n);
    z[0] = n;  
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while(i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if(i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

void run() {
    string s;
    cin >> s;
    vector<int> z = z_function(s);
    for(int i = 0; i < s.length(); i++) {
        cout << z[i] << " ";
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    run();
    return 0;
}