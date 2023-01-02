#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


int main() {
    string s;
    cin >> s;

    int n = s.length();

    map<char, int> characters;
    for (int i = 0; i < n; i++) {
        if (characters.find(s[i]) == characters.end()) characters[s[i]] = 1;
        else characters[s[i]]++;
    }

    int numOdd = 0;
    for (auto item : characters) {
        if (item.second % 2 != 0) numOdd++;
    }

    if (numOdd > 1) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    char ans[n+1];
    ans[n] = '\0';

    int i = 0;
    for (auto item : characters) {
        while (item.second != (item.second % 2 != 0)) {
            ans[i] = item.first;
            ans[n-i-1] = item.first;
            item.second -= 2;
            i++;
        }

        if (item.second == 1) ans[n/2] = item.first;
    }

    cout << ans << endl;

    return 0;
}