#include <bits/stdc++.h>
using namespace std;

int dfs(int n, vector<int> &dp) {
    if (n == 0) {
        return 0;
    }
    if (dp[n] != -1) {
        return dp[n];
    }
    int x = n;
    int r = INT_MAX;
    while (x > 0) {
        int ld = x % 10;
        if (ld != 0) {
            r = min(r, 1 + dfs(n - ld, dp));
        }
        x = x / 10;
    }
    return dp[n] = r;
}

void solve() {
    int n;
    cin >> n;
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        int x = i;
        int r = INT_MAX;
        while (x > 0) {
            int ld = x % 10;
            if (ld != 0) {
                r = min(r, 1 + dp[i - ld]);
            }
            x = x / 10;
        }
        dp[i] = r;
    }
    cout << dp[n] << '\n';
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