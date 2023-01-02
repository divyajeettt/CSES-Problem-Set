#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


int main() {
    ll n;
    cin >> n;

    ll sum = n * (n+1) / 2;

    for (ll i = 0; i < n-1; i++) {
        ll x;
        cin >> x;
        sum -= x;
    }

    cout << sum << endl;

    return 0;
}