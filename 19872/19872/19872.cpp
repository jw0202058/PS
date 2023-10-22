#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define ll long long
#define pair pair<int, int>
using namespace std;

int main(void) {
    FAST_IO

    int X;
    int res = 1;
    cin >> X;

    if (X == 0) {
        cout << 1;
        return 0;
    }

    for (int i = X; i > 0; i--) {
        //cout << res<<'\n';
        res *= i;
    }

    cout << res;

    return 0;
}