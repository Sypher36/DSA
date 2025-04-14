#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    long long tsum = 0;
    for (int &x : a) {
        cin >> x;
        tsum += x;
    }
    int bit = (1 << n) - 1;
    long long r = LONG_MAX;
    for (int i = 0; i <= bit; ++i) {
        long long sum = 0;
        for (int k = 0; k < n; ++k) {
            if (((i >> k) & 1) == 1) {
                sum += a[k];
            }
        }
        r = min(r, abs(sum - (tsum - sum)));
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