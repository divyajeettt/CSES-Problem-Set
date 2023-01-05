#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


int main() {
    ll n;
    cin >> n;

    ll count = 0;
    multiset<ll> towers;

    for (ll i = 0; i < n; i++) {
        ll k;
        cin >> k;
        auto limit = towers.upper_bound(k);

        if (limit == towers.end())
            count++;
        else
            towers.erase(limit);

        towers.insert(k);
    }

    cout << count << endl;

    return 0;
}