#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }
    int pos[n];
    for (int i = 0; i < n; ++i) {
        pos[a[i]] = i;
    }
    int r = 0;
    for (int i = 1; i < n; ++i) {
        if (pos[i - 1] > pos[i]) {
            ++r;
        }
    }
    cout << r + 1 << '\n';
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