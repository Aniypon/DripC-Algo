#include <iostream>
#include <vector>
#include <string>

using namespace std;

int findMinLength(const string &s) {
    int n = s.size();
    vector<int> lps(n, 0);
    int len = 0;
    int i = 1;

    while (i < n) {
        if (s[i] == s[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    int minLength = n - lps[n - 1];
    return minLength;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    int result = findMinLength(s);
    cout << result << endl;

    return 0;
}