#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Stack {
private:
    vector<int> data;
public:
    void push(int n) {
        data.push_back(n);
        cout << "ok" << endl;
    }

    void pop() {
        if (data.empty()) {
            cout << "error" << endl;
        } else {
            cout << data.back() << endl;
            data.pop_back();
        }
    }

    void back() {
        if (data.empty()) {
            cout << "error" << endl;
        } else {
            cout << data.back() << endl;
        }
    }

    void size() {
        cout << data.size() << endl;
    }

    void clear() {
        data.clear();
        cout << "ok" << endl;
    }
};

void run() {
    Stack s;
    string command;
    while (cin >> command) {
        if (command == "push") {
            int n;
            cin >> n;
            s.push(n);
        } else if (command == "pop") {
            s.pop();
        } else if (command == "back") {
            s.back();
        } else if (command == "size") {
            s.size();
        } else if (command == "clear") {
            s.clear();
        } else if (command == "exit") {
            cout << "bye" << endl;
            break;
        }
    }
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  srand(time(0));

  int cnt = 1;
  for (int i = 0; i < cnt; i++) {
    run();
  }
}