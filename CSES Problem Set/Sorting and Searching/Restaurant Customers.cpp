#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        int l = a[i].first, r = a[i].second;
        mp[l]++;
        mp[r + 1]--;
    }
    int r = 0;
    int psum = 0;
    for (auto p : mp) {
        int x = psum + p.second;
        r = max(r, x);
        psum = x;
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