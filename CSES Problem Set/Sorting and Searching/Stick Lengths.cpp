#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    int p(int node) {
        if (node == parent[node]) {
            return node;
        }
        else {
            return parent[node] = p(parent[node]);
        }
    }
    void u(int u, int v) {
        int ulp_u = p(u);
        int ulp_v = p(v);
        if (ulp_u == ulp_v) {
            return;
        }
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
    }
    sort(a.begin(), a.end());
    long long x, y;
    if ((n & 1) == 1) {
        x = y = a[n >> 1];
    }
    else {
        x = a[(n >> 1) - 1];
        y = a[n >> 1];
    }
    long long op1 = 0, op2 = 0;
    for (int i = 0; i < n; ++i) {
        op1 += abs(x - a[i]);
        op2 += abs(y - a[i]);
    }
    long long r = min(op1, op2);
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