#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


int main() {
    ll n, x;
    cin >> n >> x;

    ll p[n];
    for (ll i=0; i < n; i++) {
        cin >> p[i];
    }

    sort(p, p+n);

    ll allotted[n];
    for (ll i=0; i < n; i++) {
        allotted[i] = 0;
    }

    ll i = 0;
    ll j = n-1;
    ll count = 0;
    while (i <= j) {
        if (p[i] + p[j] <= x) {
            allotted[i] = allotted[j] = 1;
            i++; j--;
            count++;
        }
        else j--;
    }

    for (ll i=0; i < n; i++) {
        if (allotted[i] == 0) count++;
    }

    cout << count << endl;

    return 0;
}