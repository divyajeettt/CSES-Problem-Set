#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


int main() {
    int n;
    cin >> n;

    ll ans = 1;
    while (n--) {
        ans <<= 1;
        ans %= (ll) (1e9 + 7);
    }

    cout << ans << endl;

    return 0;
}