#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


int main() {
    int n;
    cin >> n;

    ll x[n];
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

	sort(x, x+n);

	ll sum = 0;
	for (int i = 0; i < n; i++) {
		if (sum + 1 < x[i]) break;
		else sum += x[i];
	}

	cout << sum + 1 << endl;

    return 0;
}