#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#define pill pair<int, ll>


bool comp(pill p, pill q) {
    return (p.second < q.second);
}


bool checkUnique(int x, int y, int z) {
    int n = 3;
    int array[n] = {x, y, z};
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (array[i] == array[j]) return false;
        }
    }
    return true;
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
        for (int j = i+1; j < n; j++) {
            pill pi = positions[i];
            pill pj = positions[j];
            pill p = {INT_MAX, x-pi.second-pj.second};

            auto limit = lower_bound(positions, positions+n, p, comp);

            if (
                limit->first <= n
                && pi.second + pj.second + limit->second == x
                && checkUnique(pi.first, pj.first, limit->first)
            ) {
                    cout << pi.first << " " << pj.first << " " << limit->first;
                    return 0;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}