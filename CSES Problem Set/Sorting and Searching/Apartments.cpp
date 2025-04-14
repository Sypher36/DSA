#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (int &x : a) {
        cin >> x;
    }
    for (int &x : b) {
        cin >> x;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int i = 0, j = 0;
    int r = 0;
    while (i < n && j < m) {
        int lb = a[i] - k, ub = a[i] + k;
        if (b[j] >= lb && b[j] <= ub) {
            r++;
            i++;
            j++;
        }
        else if (b[j] > ub) {
            i++;
        }
        else {
            j++;
        }
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