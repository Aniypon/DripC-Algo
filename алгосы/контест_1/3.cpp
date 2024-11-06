#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
  int n,coutN=0;
  cin >> n;
  while(n != 0){
    int temp = n;
    cin >> n;
    if (temp < n){
      coutN++;
    }
  }
  cout << coutN;
}