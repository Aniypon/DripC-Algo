#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long MOD = 1e9 + 7;
const long long BASE = 31;

vector<long long> getForwardHashes(const vector<int>& arr) {
    int n = arr.size();
    vector<long long> hashes(n + 1, 0);
    long long power = 1;
    
    for(int i = 0; i < n; i++) {
        hashes[i + 1] = (hashes[i] + arr[i] * power) % MOD;
        power = (power * BASE) % MOD;
    }
    return hashes;
}

vector<long long> getReverseHashes(const vector<int>& arr) {
    int n = arr.size();
    vector<long long> hashes(n + 1, 0);
    long long power = 1;
    
    for(int i = n - 1; i >= 0; i--) {
        hashes[n - i] = (hashes[n - i - 1] + arr[i] * power) % MOD;
        power = (power * BASE) % MOD;
    }
    return hashes;
}

bool isValidReflection(const vector<int>& cubes, int realCount) {
    int n = cubes.size();
    int reflectionLen = n - realCount;
    vector<int> real(cubes.begin() + realCount - reflectionLen, cubes.begin() + realCount);
    vector<int> reflection(cubes.begin() + realCount, cubes.end());
    reverse(reflection.begin(), reflection.end());
    return real == reflection;
}

void run() {
    int n, m;
    cin >> n >> m;
    vector<int> cubes(n);
    for(int i = 0; i < n; i++) {
        cin >> cubes[i];
    }
    
    vector<int> possible_lengths;
    
    for(int len = 1; len <= n; len++) {
        if(len >= n - len) { 
            if(isValidReflection(cubes, len)) {
                possible_lengths.push_back(len);
            }
        }
    }
    
    sort(possible_lengths.begin(), possible_lengths.end());
    for(int len : possible_lengths) {
        cout << len << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    run();
    return 0;
}