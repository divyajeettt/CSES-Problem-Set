#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


int main() {
    ll n, m, k;
    cin >> n >> m >> k;

    ll a[n];
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll b[m];
    for (ll i = 0; i < m; i++) {
        cin >> b[i];
    }

    sort(a, a+n);
    sort(b, b+m);

    ll ans = 0;
    ll i = 0, j = 0;
    while (i < n && j < m)
    {
        if (b[j]-k <= a[i] && a[i] <= b[j]+k) {
            ans++; i++; j++;
        }
        else if (b[j]-k > a[i]) i++;
        else j++;
    }

    cout << ans << endl;

    return 0;
}