#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


int main() {
    ll n, m;
    cin >> n >> m;

    multiset<ll> prices;
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        prices.insert(x);
    }

    ll customers[m];
    for (ll i = 0; i < m; i++) {
        ll x;
        cin >> x;
        customers[i] = x;
    }

    for (ll i = 0; i < m; i++) {
        if (prices.size() == 0) cout << -1 << endl;
        else{
            auto itr = prices.lower_bound(customers[i]);
            if (itr == prices.end()) itr--;
            if (*itr <= customers[i]) {
                cout << *itr << endl;
                prices.erase(itr);
            }
            else if (itr == prices.begin()) cout << -1 << endl;
            else {
                itr--;
                cout << *itr << endl;
                prices.erase(itr);
            }
        }
    }

    return 0;
}