#include <bits/stdc++.h>
using namespace std;

int dfs(int sum, vector<int> &dp) {
    if (sum == 0) {
        return 1;
    }
    if (dp[sum] != -1) {
        return dp[sum];
    }
    int r = 0;
    for (int i = 1; i <= min(sum, 6); ++i) {
        r += dfs(sum - i, dp);
    }
    return dp[sum] = r;
}

void solve() {
    int MOD = 1000000007;
    int n;
    cin >> n;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int sum = 1; sum <= n; ++sum) {
        int r = 0;
        for (int i = 1; i <= min(sum, 6); ++i) {
            r += dp[sum - i];
            r = r % MOD;
        }
        dp[sum] = r;
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