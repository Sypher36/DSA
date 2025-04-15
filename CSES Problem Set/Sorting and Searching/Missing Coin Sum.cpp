#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long &x : a) {
        cin >> x;
    }
    sort(a.begin(), a.end());
    long long mx = 0;
    for (long long i = 0; i < n; ++i) {
        long long l = a[i], r = a[i] + mx;
        if (l - mx > 1) {
            cout << mx + 1 << '\n';
            return;
        }
        mx = r;
    }
    cout << mx + 1 << '\n';
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