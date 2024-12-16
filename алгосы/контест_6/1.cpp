#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define pb push_back
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define vi vector<int>
#define vvi vector<vi>
#define fori(a, b, c) for (int i = a; i < b; i += c)

const int inf = 1e15;
const int ninf = -1e15;
const double EPS = 1e-9;

void run() {
    stack<int> s;
    string command;
    while (cin >> command) {
        if (command == "push") {
            int n;
            cin >> n;
            s.push(n);
            cout << "ok" << endl;
        } else if (command == "pop") {
            cout << s.top() << endl;
            s.pop();
        } else if (command == "back") {
            cout << s.top() << endl;
        } else if (command == "size") {
            cout << s.size() << endl;
        } else if (command == "clear") {
            while (!s.empty()) {
                s.pop();
            }
            cout << "ok" << endl;
        } else if (command == "exit") {
            cout << "bye" << endl;
            break;
        }
    }
}

int32_t main() {
    run();
    return 0;
}