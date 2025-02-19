#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<string> get_substrings(string s) {
    vector<string> result;
    for (int len = 1; len <= s.length(); len++) {
        for (int i = 0; i + len <= s.length(); i++) {
            result.push_back(s.substr(i, len));
        }
    }
    return result;
}

int sum_of_digits(int n) {
    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

struct State {
    int number;
    int cost;
    int steps;
    vector<pair<int, bool>> path;

    State(int n, int c, int s) : number(n), cost(c), steps(s) {
    }
};

struct CompareState {
    bool operator()(const State &a, const State &b) const {
        if (a.cost != b.cost)
            return a.cost > b.cost;
        return a.steps > b.steps;
    }
};

int32_t main() {
    int n, a, b;
    cin >> n >> a >> b;

    priority_queue<State, vector<State>, CompareState> pq;
    const int INF = 1e18;
    vector<int> bestCost(n + 1, INF);
    vector<int> bestSteps(n + 1, INF);

    State start(a, 0, 0);
    pq.push(start);
    bestCost[a] = 0;
    bestSteps[a] = 0;

    State *answer = nullptr;

    while (!pq.empty()) {
        State curr = pq.top();
        pq.pop();

        if (curr.number == b) {
            answer = new State(curr);
            break;
        }

        if (curr.cost > bestCost[curr.number] ||
            (curr.cost == bestCost[curr.number] && curr.steps > bestSteps[curr.number]))
            continue;

        vector<string> subs = get_substrings(to_string(curr.number));
        for (auto &sub : subs) {
            int y = stoll(sub);
            if (y == 0)
                continue;

            if (curr.number + y <= n) {
                int newCost = curr.cost + sum_of_digits(y);
                int newSteps = curr.steps + 1;
                if (newCost < bestCost[curr.number + y] ||
                    (newCost == bestCost[curr.number + y] && newSteps < bestSteps[curr.number + y])) {
                    bestCost[curr.number + y] = newCost;
                    bestSteps[curr.number + y] = newSteps;
                    State next(curr.number + y, newCost, newSteps);
                    next.path = curr.path;
                    next.path.push_back({y, true});
                    pq.push(next);
                }
            }

            if (curr.number - y > 0) {
                int newCost = curr.cost + sum_of_digits(y);
                int newSteps = curr.steps + 1;
                if (newCost < bestCost[curr.number - y] ||
                    (newCost == bestCost[curr.number - y] && newSteps < bestSteps[curr.number - y])) {
                    bestCost[curr.number - y] = newCost;
                    bestSteps[curr.number - y] = newSteps;
                    State next(curr.number - y, newCost, newSteps);
                    next.path = curr.path;
                    next.path.push_back({y, false});
                    pq.push(next);
                }
            }
        }
    }

    if (answer == nullptr) {
        cout << -1 << endl;
    } else {
        cout << answer->cost << endl;
        cout << answer->steps << endl;
        for (auto &step : answer->path) {
            cout << (step.second ? "+" : "-") << step.first << endl;
        }
    }

    return 0;
}