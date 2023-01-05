#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#define pill pair<int, ll>


bool comp(pill p, pill q) {
    return (p.second < q.second);
}


int main() {
    int n;
    ll x;
    cin >> n >> x;

    pill positions[n];
    for (int i = 0; i < n; i++) {
        ll p;
        cin >> p;
        positions[i] = {i+1, p};
    }

    sort(positions, positions+n, comp);

    for (int i = 0; i < n; i++) {
        pill p = {INT_MAX, x-positions[i].second};
        auto limit = lower_bound(positions, positions+n, p, comp);

        if (limit->first <= n && positions[i].second + limit->second == x && positions[i].first != limit->first) {
            cout << positions[i].first << " " << limit->first;
            return 0;
        }
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}