#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int id = 0;
    for (int i = 2; i <= n; i += 2) {
        a[id++] = i;
    }
    for (int i = 1; i <= n; i += 2) {
        a[id++] = i;
    }
    for (int i = 1; i < n; ++i) {
        if (abs(a[i] - a[i - 1]) == 1) {
            cout << "NO SOLUTION\n";
            return;
        }
    }
    for (int x : a) {
        cout << x << ' ';
    }
    cout << '\n';
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