#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    vector<int> freq(26, 0);
    for(char c : s) {
        freq[c - 'A']++;
    }
    
    string left;
    char middle = 0;
    
    for(char c = 'A'; c <= 'Z'; c++) {
        if(freq[c - 'A'] % 2 == 1) {
            middle = c;
            freq[c - 'A']--;
            break;
        }
    }
    
    for(char c = 'A'; c <= 'Z'; c++) {
        for(int i = 0; i < freq[c - 'A']/2; i++) {
            left += c;
        }
    }
    
    string result = left;
    if(middle) result += middle;
    string right = left;
    reverse(right.begin(), right.end());
    result += right;
    
    cout << result << "\n";
    
    return 0;
}