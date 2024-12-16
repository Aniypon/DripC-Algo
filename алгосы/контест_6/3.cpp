#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Queue {
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
            cout << data.front() << endl;
            data.erase(data.begin());
        }
    }

    void front() {
        if (data.empty()) {
            cout << "error" << endl;
        } else {
            cout << data.front() << endl;
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
    Queue q;
    string command;
    while (cin >> command) {
        if (command == "push") {
            int n;
            cin >> n;
            q.push(n);
        } else if (command == "pop") {
            q.pop();
        } else if (command == "front") {
            q.front();
        } else if (command == "size") {
            q.size();
        } else if (command == "clear") {
            q.clear();
        } else if (command == "exit") {
            cout << "bye" << endl;
            break;
        }
    }
}

int main() {
    srand(time(0));

    int cnt = 1;

    for (int i = 0; i < cnt; i++) {
        run();
    }
    return 0;
}