#include <iostream>
#include <string>
#include <vector>

using namespace std;

void run() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> d1(n);
    vector<int> d2(n);
    long long q = 0;

    for (int i = 0, l = 0, r = -1; i < n; ++i) {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) {
            ++k;
        }
        d1[i] = k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
        if (d1[i] > 1)
            q += d1[i] - 1;
    }

    for (int i = 0, l = 0, r = -1; i < n; ++i) {
        int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
        while (i - k - 1 >= 0 && i + k < n && s[i - k - 1] == s[i + k]) {
            ++k;
        }
        d2[i] = k--;
        if (i + k > r) {
            l = i - k - 1;
            r = i + k;
        }
        if (d2[i] > 0)
            q += d2[i];
    }

    cout << q << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    run();

    return 0;
}