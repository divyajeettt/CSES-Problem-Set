#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


int main() {
    string s;
    cin >> s;

    ll n = s.length();

    char curr = 'X';
    ll longest = 0;
    ll maxCount = 0;

    for (auto chr : s) {
        if (chr == curr) longest++;
        else {
            maxCount = max(longest, maxCount);
            longest = 1;
            curr = chr;
        }
    }

    maxCount = max(longest, maxCount);
    cout << maxCount << endl;

    return 0;
}