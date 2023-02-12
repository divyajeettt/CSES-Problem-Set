#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#define MOD (ll) (1e9 + 7)


int main() {
    int n;
    cin >> n;

    ll table[n+20];
    table[0] = 0;
    table[1] = 1;

    for (int i = 2; i <= 6; i++) {
        ll sum = 0;
        for (int j = 0; j < i; j++) sum += table[j];
        sum++;
        table[i] = sum;
    }

    if (n <= 6) {
        cout << table[n] << endl;
        return 0;
    }

    ll ans = 0;
    for (int i = 7; i <= n; i++) {
        ll sum = 0;
        sum = table[i-1] + table[i-2] + table[i-3] + table[i-4] + table[i-5] + table[i-6];
        table[i] = sum % MOD;
    }

    cout << table[n] << endl;

    return 0;
}