#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
public:
    vector<int> t;
    SegmentTree(int n) {
        t.resize(n << 2, 0);
    }
    int query(int n, int l, int h, int ql, int qh) {
        if (h < ql || qh < l) {
            return 0;
        }
        if (l >= ql && h <= qh) {
            return t[n];
        }
        int m = l + ((h - l) >> 1);
        return max(query(2 * n + 1, l, m, ql, qh), query(2 * n + 2, m + 1, h, ql, qh));
    }
    void update(int n, int l, int h, int i, int val) {
        if (l == h) {
            t[n] = val;
            return;
        }
        int m = l + ((h - l) >> 1);
        if (i <= m) {
            update(2 * n + 1, l, m, i, val);
        }
        else {
            update(2 * n + 2, m + 1, h, i, val);
        }
        t[n] = max(t[2 * n + 1], t[2 * n + 2]);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    int st = 1;
    for (int i = 0; i < n; ++i) {
        int x = a[i].first;
        a[i].first = st;
        while (i + 1 < n && a[i + 1].first == x) {
            a[++i].first = st;
        }
        ++st;
    }
    sort(a.begin(), a.end(), [](const pair<int, int> &p1, const pair<int, int> &p2) { return p1.second < p2.second; });
    SegmentTree t(st + 1);
    for (int i = 0; i < n; ++i) {
        int x = a[i].first;
        int put = 1 + t.query(0, 0, st, 0, x - 1);
        t.update(0, 0, st, x, put);
    }
    int mx = t.query(0, 0, st, 0, st - 1);
    cout << mx << '\n';
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