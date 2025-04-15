#include <bits/stdc++.h>
using namespace std;

int dfs(int i, int c, vector<int> &a, vector<int> &b, vector<vector<int>> &dp) {
    if (i == 0) {
        return c >= a[0] ? b[0] : 0;
    }
    if (dp[i][c] != -1) {
        return dp[i][c];
    }
    int pick = 0;
    if (c >= a[i]) {
        pick = b[i] + dfs(i - 1, c - a[i], a, b, dp);
    }
    int notPick = dfs(i - 1, c, a, b, dp);
    return dp[i][c] = max(pick, notPick);
}

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n);
    for (int &x : a) {
        cin >> x;
    }
    for (int &x : b) {
        cin >> x;
    }
    vector<int> prev(x + 1, 0), curr(x + 1, 0);
    for (int c = 0; c <= x; ++c) {
        prev[c] = c >= a[0] ? b[0] : 0;
    }
    for (int i = 1; i < n; ++i) {
        for (int c = 0; c <= x; ++c) {
            int pick = c >= a[i] ? b[i] + prev[c - a[i]] : 0;
            int notPick = prev[c];
            curr[c] = max(pick, notPick);
        }
        prev = curr;
    }
    int r = prev[x];
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