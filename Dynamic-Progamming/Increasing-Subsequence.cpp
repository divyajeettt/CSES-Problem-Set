#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


int main() {
    int n;
    cin >> n;

    ll x[n];
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    vector<ll> tail(n, 0);
    int length = 1;
    tail[0] = x[0];

    for (int i = 1; i < n; i++) {
        auto start = tail.begin();
        auto end = tail.begin() + length;
        auto index = lower_bound(start, end, x[i]);

        if (index == end)
            tail[length++] = x[i];
        else
            *index = x[i];
    }

    cout << length << endl;

    return 0;
}