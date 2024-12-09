#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1e9 + 7;
vector<int> symmetric_numbers;

bool isValidVertical(char c) {
    return c != '3' && c != '4' && c != '7';
}

void generateSymmetricNumbers(int len) {
    function<void(string&, int, int)> genVertical = [&](string& num, int pos, int total) {
        if (pos > total / 2) {
            if (all_of(num.begin(), num.end(), isValidVertical)) {
                symmetric_numbers.push_back(stoll(num));
            }
            return;
        }
        
        for (char d = '0'; d <= '9'; d++) {
            num[pos] = d;
            num[total - 1 - pos] = d;
            genVertical(num, pos + 1, total);
        }
    };

    function<void(string&, int, int)> genHorizontal = [&](string& num, int pos, int total) {
        if (pos > total / 2) {
            symmetric_numbers.push_back(stoll(num));
            return;
        }
        
        for (char d = '0'; d <= '9'; d++) {
            num[pos] = d;
            num[total - 1 - pos] = (d == '2' ? '5' : (d == '5' ? '2' : d));
            genHorizontal(num, pos + 1, total);
        }
    };

    string number(len, '0');
    genVertical(number, 0, len);
    genHorizontal(number, 0, len);
}

void precompute(int maxLen) {
    for (int len = 1; len <= maxLen; len++) {
        generateSymmetricNumbers(len);
    }
    sort(symmetric_numbers.begin(), symmetric_numbers.end());
    symmetric_numbers.erase(unique(symmetric_numbers.begin(), symmetric_numbers.end()), 
                          symmetric_numbers.end());
}

void run() {
    int a, b;
    cin >> a >> b;
    
    int maxLen = to_string(b).length();
    precompute(maxLen);
    
    auto it_begin = lower_bound(symmetric_numbers.begin(), symmetric_numbers.end(), a);
    auto it_end = upper_bound(symmetric_numbers.begin(), symmetric_numbers.end(), b);
    
    cout << ((it_end - it_begin) % MOD) << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int cnt = 1;
    for (int i = 0; i < cnt; i++) {
        run();
    }
    return 0;
}