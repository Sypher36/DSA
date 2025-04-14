#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> a(26, 0);
    int odd = 0;
    char oddEl = ' ';
    for (int i = 0; i < n; ++i) {
        a[s[i] - 'A']++;
    }
    for (int i = 0; i < 26; ++i) {
        if ((a[i] & 1) == 1) {
            ++odd;
            oddEl = i + 'A';
        }
    }
    if (odd > 1) {
        cout << "NO SOLUTION\n";
        return;
    }
    int x = 0;
    for (int i = 25; i >= 0; --i) {
        while (a[i] > 1) {
            s[x] = s[n - x - 1] = i + 'A';
            ++x;
            a[i] = a[i] - 2;
        }
    }
    if ((n & 1) == 1) {
        s[x] = oddEl;
    }
    cout << s << '\n';
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