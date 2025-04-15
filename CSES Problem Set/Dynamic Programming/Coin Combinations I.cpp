#include <bits/stdc++.h>
using namespace std;

int dfs(int sum, vector<int> &a, int &n, vector<int> &dp) {
    if (sum == 0) {
        return 1;
    }
    if (dp[sum] != -1) {
        return dp[sum];
    }
    int r = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] <= sum) {
            r += dfs(sum - a[i], a, n, dp);
        }
    }
    return dp[sum] = r;
}

void solve() {
    int MOD = 1000000007;
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
    }
    vector<int> dp(s + 1, 0);
    dp[0] = 1;
    for (int sum = 1; sum <= s; ++sum) {
        for (int i = 0; i < n; ++i) {
            if (a[i] <= sum) {
                dp[sum] = (dp[sum] + dp[sum - a[i]]) % MOD;
            }
        }
    }
    cout << dp[s] << '\n';
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