#include <iostream>
using namespace std;

#define int long long

int32_t main() {
    int n;
    cin >> n;

    int branches_area = n * (n + 1);
    int trunk_area = n * 2 + 1;
    int total_area = branches_area + trunk_area;

    cout << total_area << endl;

    return 0;
}