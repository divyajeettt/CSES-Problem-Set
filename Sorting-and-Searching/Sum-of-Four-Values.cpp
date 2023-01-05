#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#define pill pair<int, ll>
#define tiill tuple<int, int, ll>


bool comp(tiill t, tiill s) {
    return (get<2>(t) < get<2>(s));
}


bool checkUnique(int w, int x, int y, int z) {
    int n = 4;
    int array[n] = {w, x, y, z};
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

    tiill sums[n * n / 2];
    int m = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            pill pi = positions[i];
            pill pj = positions[j];
            sums[m++] = {pi.first, pj.first, pi.second + pj.second};
        }
    }

    sort(sums, sums+m, comp);

    for (int i = 0; i < m; i++) {
        tiill search = {INT_MAX, INT_MAX, x-get<2>(sums[i])};

        auto limit = *lower_bound(sums, sums+m, search, comp);
        int s0 = get<0>(sums[i]);
        int s1 = get<1>(sums[i]);
        int l0 = get<0>(limit);
        int l1 = get<1>(limit);

        if (
            l0 <= n && l1 <= n
            && get<2>(sums[i]) + get<2>(limit) == x
            && checkUnique(s0, s1, l0, l1)
        ) {
                cout << s0 << " " << s1 << " " << l0 << " " << l1 << endl;
                return 0;
        }
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}