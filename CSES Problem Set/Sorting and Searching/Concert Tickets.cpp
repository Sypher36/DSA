#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int &x : a) {
        cin >> x;
    }
    for (int &x : b) {
        cin >> x;
    }
    multiset<int> s(a.begin(), a.end());
    vector<int> r(m, -1);
    for (int i = 0; i < m; ++i) {
        auto it = s.upper_bound(b[i]);
        if (it == s.begin()) {
            continue;
        }
        --it;
        r[i] = *it;
        s.erase(it);
    }
    for (int x : r) {
        cout << x << '\n';
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