#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n;
    cin >> n;
    long long r = 2;
    for (int i = 1; i < n; ++i) {
        r = (r * 2) % 1000000007;
    }
    cout << r << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; ++i) {
        solve();
    }
    return 0;
}