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

int32_t main() {
    int N;
    cin >> N;

    unordered_map<string, string> parentOf;
    unordered_map<string, vector<string>> childrenOf;
    unordered_set<string> allNames;

    for(int i = 0; i < N - 1; i++){
        string child, parent;
        cin >> child >> parent;
        parentOf[child] = parent;
        childrenOf[parent].push_back(child);
        allNames.insert(child);
        allNames.insert(parent);
    }

    string root;
    for(const auto &name : allNames){
        if(!parentOf.count(name)){
            root = name;
            break;
        }
    }

    unordered_map<string,int> height;
    height[root] = 0;

    queue<string>q;
    q.push(root);

    while(!q.empty()){
        auto cur = q.front(); 
        q.pop();
        int curH = height[cur];
        for(auto &ch : childrenOf[cur]){
            height[ch] = curH + 1;
            q.push(ch);
        }
    }

    vector<string> sortedNames(allNames.begin(), allNames.end());
    sort(sortedNames.begin(), sortedNames.end());

    for(auto &name : sortedNames){
        cout << name << " " << height[name] << "\n";
    }

    return 0;

}