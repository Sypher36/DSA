#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
public:
    vector<int> T;
    int n;
    SegmentTree(vector<int> &a) {
        this->n = a.size();
        T.resize(this->n * 4, 0);
        build(0, 0, n - 1, a);
    }
    void assign(int node) {
        T[node] = min(T[2 * node + 1], T[2 * node + 2]);
    }
    void build(int node, int l, int h, vector<int> &a) {
        if (l == h) {
            T[node] = a[l];
            return;
        }
        int mid = l + ((h - l) >> 1);
        build(2 * node + 1, l, mid, a);
        build(2 * node + 2, mid + 1, h, a);
        assign(node);
    }
    int query(int node, int l, int h, int ql, int qh) {
        if (h < ql || qh < l) {
            return INT_MAX;
        }
        if (l >= ql && h <= qh) {
            return T[node];
        }
        int mid = l + ((h - l) >> 1);
        return min(query(2 * node + 1, l, mid, ql, qh), query(2 * node + 2, mid + 1, h, ql, qh));
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
    }
    SegmentTree t(a);
    for (int i = 0; i < q; ++i) {
        int l, h;
        cin >> l >> h;
        int mn = t.query(0, 0, n - 1, l - 1, h - 1);
        cout << mn << '\n';
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