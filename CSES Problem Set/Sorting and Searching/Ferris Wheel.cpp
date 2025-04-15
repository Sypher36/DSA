#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
    }
    vector<bool> vis(n, false);
    sort(a.begin(), a.end());
    int i = 0, j = n - 1;
    int r = 0;
    while (i < j) {
        if (a[i] + a[j] <= k) {
            ++r;
            vis[i] = vis[j] = true;
            ++i;
            --j;
        }
        else {
            --j;
        }
    }
    for (int i = 0; i < n; ++i) {
        r += vis[i] == false;
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