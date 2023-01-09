#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


int divisors(int n) {
    int count = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        count += (n%i == 0);
        if (i != n/i) count += (n%(n/i) == 0);
    }
    return count;
}


int main() {
    int n;
    cin >> n;

    while (n--) {
        int x;
        cin >> x;
        cout << divisors(x) << endl;
    }

    return 0;
}