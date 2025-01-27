#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

const int inf = 1e15;
const int ninf = -1e15;
const double EPS = 1e-9;

void dfs(string curr, map<string, string>& parent, map<string, int>& height) {
    if (height.count(curr))
        return;

    if (parent.count(curr) == 0) {
        height[curr] = 0;
    } else {
        dfs(parent[curr], parent, height);
        height[curr] = height[parent[curr]] + 1;
    }
}

int32_t main() {
    int n;
    cin >> n;

    map<string, string> parent;
    set<string> names;

    for (int i = 0; i < n - 1; i++) {
        string child, par;
        cin >> child >> par;
        parent[child] = par;
        names.insert(child);
        names.insert(par);
    }

    map<string, int> height;
    for (const string& name : names) {
        dfs(name, parent, height);
    }

    for (const string& name : names) {
        cout << name << " " << height[name] << endl;
    }

    return 0;
}