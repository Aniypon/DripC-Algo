#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
const ull P = 131;  

void run() {
    string s;
    cin >> s;
    int n = s.length();

    vector<ull> prefix_hash(n + 1, 0);
    vector<ull> powers(n + 1, 1);

    for (int i = 0; i < n; i++) {
        prefix_hash[i + 1] = prefix_hash[i] * P + s[i];
        powers[i + 1] = powers[i] * P;
    }

    unordered_set<ull> candidates;

    for (int len = 1; len <= n; len++) {
        unordered_map<ull, vector<int>> hash_positions;
        for (int i = 0; i + len <= n; i++) {
            ull current_hash = prefix_hash[i + len] - prefix_hash[i] * powers[len];
            hash_positions[current_hash].push_back(i);
        }
        
        for (const auto& entry : hash_positions) {
            const vector<int>& positions = entry.second;
            for (int i = 1; i < positions.size(); i++) {
                if (positions[i] - positions[i - 1] >= len) {
                    candidates.insert(entry.first);
                    break;
                }
            }
        }
    }

    cout << candidates.size() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    run();
    return 0;
}