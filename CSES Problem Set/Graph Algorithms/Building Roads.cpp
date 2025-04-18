#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> parent, size;
    int components;

public:
    int getComponents() {
        return this->components;
    }
    DSU(int n) {
        components = n;
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    int getParent(int node) {
        if (node == parent[node]) {
            return node;
        }
        else {
            return parent[node] = getParent(parent[node]);
        }
    }
    void connect(int u, int v) {
        int ulp_u = getParent(u);
        int ulp_v = getParent(v);
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
    int n, e;
    cin >> n >> e;
    DSU unionFind(n);
    for (int i = 0; i < e; ++i) {
        int u, v;
        cin >> u >> v;
        unionFind.connect(u, v);
    }
    set<int> s;
    for (int i = 1; i <= n; ++i) {
        s.insert(unionFind.getParent(i));
    }
    cout << unionFind.getComponents() - 1 << '\n';
    int prev = -1;
    for (int x : s) {
        if (prev != -1) {
            cout << prev << ' ' << x << '\n';
        }
        prev = x;
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