#include <iostream>
#include <sstream>
#include <stack>
#include <string>

using namespace std;

int evaluatePostfix(const string& expression) {
    stack<int> s;
    istringstream iss(expression);
    string token;

    while (iss >> token) {
        if (isdigit(token[0])) {
            s.push(stoi(token));
        } else {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            if (token == "+") {
                s.push(a + b);
            } else if (token == "-") {
                s.push(a - b);
            } else if (token == "*") {
                s.push(a * b);
            }
        }
    }

    return s.top();
}

void run() {
    string expression;
    getline(cin, expression);
    cout << evaluatePostfix(expression) << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    run();
    return 0;
}