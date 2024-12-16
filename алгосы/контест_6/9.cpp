#include <iostream>
#include <queue>
#include <string>

using namespace std;

void run() {
    queue<int> first, second;
    int card;

    for (int i = 0; i < 5; ++i) {
        cin >> card;
        first.push(card);
    }

    for (int i = 0; i < 5; ++i) {
        cin >> card;
        second.push(card);
    }

    int rounds = 0;
    while (!first.empty() && !second.empty() && rounds < 1000000) {
        int first_card = first.front();
        int second_card = second.front();
        first.pop();
        second.pop();

        if ((first_card > second_card && !(first_card == 9 && second_card == 0)) || (first_card == 0 && second_card == 9)) {
            first.push(first_card);
            first.push(second_card);
        } else {
            second.push(first_card);
            second.push(second_card);
        }

        ++rounds;
    }

    if (first.empty()) {
        cout << "second " << rounds << endl;
    } else if (second.empty()) {
        cout << "first " << rounds << endl;
    } else {
        cout << "botva" << endl;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    run();
    return 0;
}