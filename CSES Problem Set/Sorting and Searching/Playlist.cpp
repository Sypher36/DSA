#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, size;
    int components;
    DSU(int n) {
        components = n;
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
        --components;
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
    map<int, int> mp;
    int r = 0;
    for (int i = 0, j = -1; i < n; ++i) {
        while (j + 1 < n && mp.find(a[j + 1]) == mp.end()) {
            mp[a[++j]]++;
        }
        r = max(r, j - i + 1);
        mp.erase(a[i]);
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