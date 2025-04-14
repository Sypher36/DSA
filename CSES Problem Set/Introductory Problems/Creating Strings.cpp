#include <bits/stdc++.h>
using namespace std;

void dfs(string &p, string &s, vector<bool> &vis, set<string> &st) {
    if (p.size() == s.size()) {
        st.insert(p);
        return;
    }
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            vis[i] = true;
            p.push_back(s[i]);
            dfs(p, s, vis, st);
            p.pop_back();
            vis[i] = false;
        }
    }
}

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    set<string> st;
    string p = "";
    vector<bool> vis(n, false);
    dfs(p, s, vis, st);
    cout << st.size() << '\n';
    for (const string &x : st) {
        cout << x << '\n';
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