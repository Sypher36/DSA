#include <bits/stdc++.h>
using namespace std;

int dfs(int i, int j, vector<vector<char>> &a, vector<vector<int>> &dp) {
    if (i == 0 && j == 0) {
        return 1;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    int up = 0;
    if (i > 0 && a[i - 1][j] != '*') {
        up = dfs(i - 1, j, a, dp);
    }
    int le = 0;
    if (j > 0 && a[i][j - 1] != '*') {
        le = dfs(i, j - 1, a, dp);
    }
    return dp[i][j] = up + le;
}

void solve() {
    int MOD = 1000000007;
    int n;
    cin >> n;
    vector<vector<char>> a(n, vector<char>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    if (a[0][0] == '*' || a[n - 1][n - 1] == '*') {
        cout << "0 \n";
        return;
    }
    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 0 && j == 0) {
                continue;
            }
            int up = 0;
            if (i > 0 && a[i - 1][j] != '*') {
                up = dp[i - 1][j];
            }
            int le = 0;
            if (j > 0 && a[i][j - 1] != '*') {
                le = dp[i][j - 1];
            }
            dp[i][j] = (up + le) % MOD;
        }
    }
    cout << dp[n - 1][n - 1] << '\n';
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