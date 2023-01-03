#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


string replicate(string s, ll n) {
    string ans;
    ans.reserve(n * s.size());
    while (n--) ans += s;
    return ans;
}


void generateCodes(ll width, string array[], ll len) {
    if (len == 1) {
        array[len-1] = replicate("0", width);
        array[len] = array[len-1];
        array[len][width-1] = '1';
    }

    if (len == width) return;

    ll toCopy = (ll) pow(2, len);
    for (ll i = 0; i < toCopy; i++) {
        array[toCopy+i] = array[i];
        array[toCopy+i][len-1] = '1';
    }

    for (ll i = 0; i < toCopy/2; i++) {
        string temp = array[i];
        array[i] = array[toCopy-i-1];
        array[toCopy-i-1] = temp;
    }

    generateCodes(width, array, len+1);
}


int main() {
    int n;
    cin >> n;

    ll count = (ll) pow(2, n);

    string codes[count];
    generateCodes(n, codes, 1);

    for (ll i = 0; i < count; i++) cout << codes[i] << endl;

    return 0;
}