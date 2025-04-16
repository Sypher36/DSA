#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
    }
    vector<long long> psum(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        psum[i] = psum[i - 1] + a[i - 1];
    }
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        cout << psum[r] - psum[l - 1] << '\n';
    }
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