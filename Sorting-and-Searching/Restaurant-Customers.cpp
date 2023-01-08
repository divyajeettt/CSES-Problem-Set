#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#define pllb pair<ll, bool>


bool comp(pllb p, pllb q) {
    return (p.first < q.first);
}


int main() {
    int n;
    cin >> n;

    vector<pllb> times;
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        times.push_back({a, true});
        times.push_back({b, false});
    }

    sort(times.begin(), times.end(), comp);

    ll counter = 0;
    ll maxCounter = counter;
    for (auto i = times.begin(); i != times.end(); i++) {
        if ((*i).second) {
            counter++;
            if (counter > maxCounter) maxCounter = counter;
        }
        else counter--;
    }

    cout << maxCounter << endl;

    return 0;
}