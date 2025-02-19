#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Stop {
    int station;
    int time;
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, E;
    cin >> N >> E;
    int M;
    cin >> M;

    vector<vector<Stop>> routes(M);
    for (int i = 0; i < M; i++) {
        int K;
        cin >> K;
        routes[i].resize(K);
        for (int j = 0; j < K; j++) {
            cin >> routes[i][j].station >> routes[i][j].time;
        }
    }

    const int INF = 1e18;
    vector<int> earliest(N + 1, INF);
    earliest[1] = 0;

    using State = pair<int, int>;
    priority_queue<State, vector<State>, greater<State>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [currTime, station] = pq.top();
        pq.pop();

        if (currTime > earliest[station])
            continue;

        if (station == E) {
            cout << currTime << "\n";
            return 0;
        }


        for (int i = 0; i < M; i++) {
            int boardingIndex = -1;
            for (int j = 0; j < routes[i].size(); j++) {
                if (routes[i][j].station == station && routes[i][j].time >= currTime) {
                    boardingIndex = j;
                    break;
                }
            }
            if (boardingIndex == -1)
                continue;

            for (int j = boardingIndex + 1; j < routes[i].size(); j++) {
                int nextStation = routes[i][j].station;
                int arrivalTime = routes[i][j].time;
                if (arrivalTime < earliest[nextStation]) {
                    earliest[nextStation] = arrivalTime;
                    pq.push({arrivalTime, nextStation});
                }
            }
        }
    }
    cout << -1 << "\n";
    return 0;
}