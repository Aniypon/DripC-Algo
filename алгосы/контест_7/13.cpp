#include <bits/stdc++.h>
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

int increaseFirst(int num) {
    int first = num / 1000;
    if (first == 9)
        return -1;
    return num + 1000;
}

int decreaseLast(int num) {
    int last = num % 10;
    if (last == 1)
        return -1;
    return num - 1;
}

int rotateRight(int num) {
    int last = num % 10;
    return last * 1000 + num / 10;
}

int rotateLeft(int num) {
    int first = num / 1000;
    return (num % 1000) * 10 + first;
}

int32_t main() {
    int start, target;
    cin >> start >> target;

    queue<int> q;
    map<int, pair<int, int>> parent;  
    set<int> visited;

    q.push(start);
    visited.insert(start);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == target)
            break;

        vector<int> next = {increaseFirst(curr), decreaseLast(curr), rotateRight(curr), rotateLeft(curr)};

        for (int i = 0; i < 4; i++) {
            if (next[i] != -1 && !visited.count(next[i])) {
                visited.insert(next[i]);
                parent[next[i]] = {curr, i};
                q.push(next[i]);
            }
        }
    }

    vector<int> path;
    for (int curr = target; curr != start; curr = parent[curr].first) {
        path.push_back(curr);
    }
    path.push_back(start);

    reverse(path.begin(), path.end());
    for (int num : path) {
        cout << num << endl;
    }

    return 0;
}