#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


int min(vector<int> arr) {
    int x = INT_MAX;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] < x) x = arr[i];
    }
    return x;
}


int main() {
    string n;
    cin >> n;
    int N = stoi(n);

    ll table[N];
    for (int i = 0; i < N; i++) {
        table[i] = 1;
    }

    for (int i = 9; i < N; i++) {
        string str = to_string(i + 1);
        vector<int> p;
        for (auto x : str) {
            if (x != '0') p.push_back(table[i - (x - '0')]);
        }
        table[i] = 1 + min(p);
    }

    cout << table[N-1] << endl;

    return 0;
}