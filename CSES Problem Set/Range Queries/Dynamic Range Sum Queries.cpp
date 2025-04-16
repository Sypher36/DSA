#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
public:
    vector<long long> T;
    long long n;
    SegmentTree(vector<long long> &a) {
        this->n = a.size();
        T.resize(this->n * 4, 0);
        build(0, 0, n - 1, a);
    }
    long long operation(long long n1, long long n2) {
        return n1 + n2;
    }
    void assign(long long node) {
        T[node] = operation(T[2 * node + 1], T[2 * node + 2]);
    }
    void build(long long node, long long l, long long h, vector<long long> &a) {
        if (l == h) {
            T[node] = a[l];
            return;
        }
        long long mid = l + ((h - l) >> 1);
        build(2 * node + 1, l, mid, a);
        build(2 * node + 2, mid + 1, h, a);
        assign(node);
    }
    long long query(long long node, long long l, long long h, long long ql, long long qh) {
        if (h < ql || qh < l) {
            return 0;
        }
        if (l >= ql && h <= qh) {
            return T[node];
        }
        long long mid = l + ((h - l) >> 1);
        return operation(query(2 * node + 1, l, mid, ql, qh), query(2 * node + 2, mid + 1, h, ql, qh));
    }
    void update(long long node, long long l, long long h, long long i, long long val) {
        if (l == h) {
            T[node] = val;
            return;
        }
        long long mid = l + ((h - l) >> 1);
        if (i <= mid) {
            update(2 * node + 1, l, mid, i, val);
        }
        else {
            update(2 * node + 2, mid + 1, h, i, val);
        }
        assign(node);
    }
};

void solve() {
    long long n, q;
    cin >> n >> q;
    vector<long long> a(n);
    for (long long &x : a) {
        cin >> x;
    }
    SegmentTree tree(a);
    for (long long i = 0; i < q; ++i) {
        long long t, l, h;
        cin >> t >> l >> h;
        if (t == 1) {
            tree.update(0, 0, n - 1, l - 1, h);
        }
        else if (t == 2) {
            long long r = tree.query(0, 0, n - 1, l - 1, h - 1);
            cout << r << '\n';
        }
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