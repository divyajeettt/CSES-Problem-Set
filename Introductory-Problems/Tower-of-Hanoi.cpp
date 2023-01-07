#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


static int MOVES = 0;
vector<pair<int, int>> moves;


void addMove(int a, int b) {
    moves.push_back({a, b});
    MOVES++;
}


void hanoi(int n, int one, int two, int three) {
    if (n == 1) addMove(one, three);
    else {
        hanoi(n-1, one, three, two);
        addMove(one, three);
        hanoi(n-1, two, one, three);
    }
}


int main() {
    int n;
    cin >> n;

    hanoi(n, 1, 2, 3);

    cout << MOVES << endl;

    for (auto move : moves) cout << move.first << " " << move.second << endl;
}