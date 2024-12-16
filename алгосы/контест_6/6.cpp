#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Deque {
private:
    vector<int> data;
public:
    void push_front(int n) {
        data.insert(data.begin(), n);
        cout << "ok" << endl;
    }

    void push_back(int n) {
        data.push_back(n);
        cout << "ok" << endl;
    }

    void pop_front() {
        if (data.empty()) {
            cout << "error" << endl;
        } else {
            cout << data.front() << endl;
            data.erase(data.begin());
        }
    }

    void pop_back() {
        if (data.empty()) {
            cout << "error" << endl;
        } else {
            cout << data.back() << endl;
            data.pop_back();
        }
    }

    void front() {
        if (data.empty()) {
            cout << "error" << endl;
        } else {
            cout << data.front() << endl;
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
    Deque d;
    string command;
    while (cin >> command) {
        if (command == "push_front") {
            int n;
            cin >> n;
            d.push_front(n);
        } else if (command == "push_back") {
            int n;
            cin >> n;
            d.push_back(n);
        } else if (command == "pop_front") {
            d.pop_front();
        } else if (command == "pop_back") {
            d.pop_back();
        } else if (command == "front") {
            d.front();
        } else if (command == "back") {
            d.back();
        } else if (command == "size") {
            d.size();
        } else if (command == "clear") {
            d.clear();
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

    run();
    return 0;
}