#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define pb push_back
#define pii pair<int,int>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define vi vector<int>
#define vvi vector<vi>
#define fori(a , b , c) for(int i = a; i < b; i+= c)

const int inf = 1e15;
const int ninf = -1e15;
const double EPS = 1e-9;

void run() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    vector<int> prefix(n + 1, 0);
    for(int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + (arr[i] == 0);
    }
    
    int k;
    cin >> k;
    
    while(k--) {
        int l, r;
        cin >> l >> r;
        cout << prefix[r] - prefix[l-1] << ' ';
    }
    cout << '\n';
}

signed main()
{
  //freopen("input.txt", "r", stdin);
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  srand(time(0));

  int cnt = 1;
  //cin >> cnt;

  for(int i = 0; i < cnt; i++){
    run();
  }
}