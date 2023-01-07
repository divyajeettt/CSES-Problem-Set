#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


int main() {
    ll n;
    cin >> n;

    ll ans = 0;
    int curr = 1;
    while (pow(5, curr) <= n) {
        ans += n / pow(5, curr++);
    }

    cout << ans << endl;

    return 0;
}