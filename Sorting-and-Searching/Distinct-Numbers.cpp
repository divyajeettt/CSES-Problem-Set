#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


int main() {
    ll n;
    cin >> n;

    ll a[n];
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a+n);

    ll ans = 1;
    for (ll i=0; i < n-1; i++) {
        if (a[i] != a[i+1]) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}