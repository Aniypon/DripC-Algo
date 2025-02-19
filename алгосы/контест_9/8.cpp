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

int n, m;
vector<vector<int>> g;
vector<string> names;

vector<int> disc, low;
vector<bool> inStack;
stack<int> st;
int timeCounter = 0;
vector<vector<int>> sccs;

void tarjanDFS(int v) {
    disc[v] = low[v] = ++timeCounter;
    st.push(v);
    inStack[v] = true;
    for (int w : g[v]) {
        if (disc[w] == -1) {
            tarjanDFS(w);
            low[v] = min(low[v], low[w]);
        } else if (inStack[w]) {
            low[v] = min(low[v], disc[w]);
        }
    }
    if (disc[v] == low[v]) {
        vector<int> comp;
        while (true) {
            int cur = st.top();
            st.pop();
            inStack[cur] = false;
            comp.push_back(cur);
            if (cur == v)
                break;
        }
        sccs.push_back(comp);
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    names.resize(n);
    for (int i = 0; i < n; i++) {
        int id;
        cin >> id;
        getline(cin, names[id]);
        if (!names[id].empty() && names[id][0] == ' ')
            names[id].erase(0, 1);
    }

    g.assign(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    disc.assign(n, -1);
    low.assign(n, -1);
    inStack.assign(n, false);

    for (int i = 0; i < n; i++) {
        if (disc[i] == -1)
            tarjanDFS(i);
    }

    vector<vector<string>> groups;
    for (auto &comp : sccs) {
        vector<string> grp;
        for (auto v : comp) {
            grp.push_back(names[v]);
        }
        sort(all(grp));
        groups.push_back(grp);
    }

    sort(all(groups), [](const vector<string> &a, const vector<string> &b) { return a.front() < b.front(); });

    for (auto &grp : groups) {
        for (auto &s : grp) {
            cout << s << "\n";
        }
        cout << "\n";
    }

    return 0;
}