#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define vi vector<int>

vi z_function(const string& s) {
    int n = s.length();
    vi z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

void run() {
    string s;
    cin >> s;
    int n = s.length();
    vi ans(n);
    
    for(int i = 0; i < n; i++) {
        string cur = s.substr(0, i + 1);
        vi z = z_function(cur);
        int len = i + 1;
        
        if(len == 1) {
            ans[i] = 1;
            continue;
        }
        
        int period = len;
        for(int j = 1; j < len; j++) {
            if(j + z[j] >= len && len % j == 0) {
                period = j;
                break;
            }
        }
        ans[i] = period;
    }
    
    for(int x : ans) 
        cout << x << " ";
    cout << "\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    run();
    return 0;
}