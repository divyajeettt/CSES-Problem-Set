#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


bool possible(ll T, ll machines[], ll n, ll threshold) {
    ll products = 0;
    for (ll i = 0; i < n; i++) {
        products += T / machines[i];
    }
    return (products >= threshold || products < 0);
}


int main() {
    ll n, t;
    cin >> n >> t;

    ll k[n];
    for (ll i = 0; i < n; i++) {
        cin >> k[i];
    }

    ll start = 0;
    ll end = LONG_LONG_MAX;
    ll mid;
    while (start <= end) {
        mid = (start + end) / 2;
        if (possible(mid, k, n, t)) end = mid - 1;
        else start = mid + 1;
    }

    cout << start << endl;

    return 0;
}