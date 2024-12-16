#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isBalanced(const string& sequence) {
    stack<char> s;
    for (char ch : sequence) {
        if (ch == '(' || ch == '[' || ch == '{') {
            s.push(ch);
        } else {
            if (s.empty()) return false;
            char top = s.top();
            s.pop();
            if ((ch == ')' && top != '(') ||
                (ch == ']' && top != '[') ||
                (ch == '}' && top != '{')) {
                return false;
            }
        }
    }
    return s.empty();
}

void run() {
    string sequence;
    cin >> sequence;
    if (isBalanced(sequence)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    run();
    return 0;
}