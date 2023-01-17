#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#define pll pair<ll, ll>


bool comp(pll p, pll q) {
    return (p.second < q.second);
}


int main() {
    int n;
    cin >> n;

    vector<pll> times;
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        times.push_back({a, b});
    }

    sort(times.begin(), times.end(), comp);

    ll currEnd = 0;
    ll counter = 0;
    for (pll time : times) {
        if (time.first >= currEnd) {
            counter++;
            currEnd = time.second;
        }
    }

    cout << counter << endl;

    return 0;
}