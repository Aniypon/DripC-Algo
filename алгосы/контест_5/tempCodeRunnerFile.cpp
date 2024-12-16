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

vector<long long> getPowers(int n) {
    vector<long long> powers(n + 1);
    powers[0] = 1;
    for(int i = 1; i <= n; i++) {
        powers[i] = (powers[i-1] * BASE) % MOD;
    }
    return powers;
}

void run() {
    int n, m;
    cin >> n >> m;
    vector<int> cubes(n);
    for(int i = 0; i < n; i++) {
        cin >> cubes[i];
    }
    
    auto forward = getForwardHashes(cubes);
    auto reverse = getReverseHashes(cubes);
    auto powers = getPowers(n);
    
    vector<int> possible_lengths;
    
    for(int len = 1; len <= n; len++) {
        long long prefix_hash = forward[len];
        long long suffix_hash = reverse[n - len];
        
        // Нормализуем хэши к одной степени
        suffix_hash = (suffix_hash * powers[len]) % MOD;
        
        if(prefix_hash == suffix_hash) {
            possible_lengths.push_back(len);
        }
    }
    
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