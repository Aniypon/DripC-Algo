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
    int n; 
    cin >> n;
    
    vector<vector<int>> adj(n, vector<int>(n));

    for(int i =0; i < n; i++){
        for (int j =0; j< n; j++){
            cin >> adj[i][j];
        }
    }
    string empty; 
    getline(cin, empty); 
    getline(cin, empty); 

    vector<int> colours(n);
    for(int i =0; i<n; i++){
        cin >> colours[i];
    }

    int bad_bridges = 0;
    for (int i =0; i <n; i++){
        for(int j = i+1; j<n; j++){
            if (adj[i][j] && colours[i]!=colours[j]){
                bad_bridges++;
            }
        }
    }

    cout << bad_bridges;

    return 0;
}