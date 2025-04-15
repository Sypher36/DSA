#include <bits/stdc++.h>
using namespace std;

int dfs(int i, int j, string &a, string &b, vector<vector<int>> &dp) {
    if (i < 0) {
        return j + 1;
    }
    if (j < 0) {
        return i + 1;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    int r = INT_MAX;
    if (a[i] == b[j]) {
        r = dfs(i - 1, j - 1, a, b, dp);
    }
    r = min(r, 1 + min({dfs(i - 1, j - 1, a, b, dp), dfs(i - 1, j, a, b, dp), dfs(i, j - 1, a, b, dp)}));
    return dp[i][j] = r;
}

void solve() {
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int r = dfs(n - 1, m - 1, a, b, dp);
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