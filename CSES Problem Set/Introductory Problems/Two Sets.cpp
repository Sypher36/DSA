#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n;
    cin >> n;
    if (((n * (n + 1)) / 2) % 2 == 1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    long long need = (n * (n + 1)) / 4;
    vector<long long> a, b;
    for (long long i = n; i > 0; --i) {
        if (need >= i) {
            a.push_back(i);
            need -= i;
        }
        else {
            b.push_back(i);
        }
    }
    cout << a.size() << '\n';
    for (auto x : a) {
        cout << x << ' ';
    }
    cout << '\n';
    cout << b.size() << '\n';
    for (auto x : b) {
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