#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#define HALF n/2
#define j HALF/2 + i
#define k (HALF+1)/2 + i


void printArray(ll array[], ll n) {
    cout << n << endl;
    for (ll i = 0; i < n; i++) cout << array[i] << " ";
    cout << endl;
}


int main() {
    ll n;
    cin >> n;

    ll sum = n * (n+1) / 2;

    if (sum%2 != 0) cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        if (n%2 == 0) {
            ll set1[HALF], set2[HALF];

            for (ll i = 0; i < HALF/2; i++) {
                set1[i] = i + 1;
                set1[j] = n - i;
                set2[i] = HALF - i;
                set2[j] = HALF + i + 1;
            }

            printArray(set1, HALF);
            printArray(set2, HALF);
        }
        else {
            ll set1[HALF], set2[HALF+1];
            set1[0] = n;

            for (ll i = 0; i < (HALF+1)/2; i++) {
                set2[i] = i + 1;
                set2[k] = n - i - 1;
            }

            for (ll i = 1; i < HALF; i++) set1[i] = j + 1;

            printArray(set1, HALF);
            printArray(set2, HALF+1);
        }
    }

    return 0;
}