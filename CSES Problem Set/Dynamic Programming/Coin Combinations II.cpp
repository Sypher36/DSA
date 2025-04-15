#include <bits/stdc++.h>
using namespace std;

int dfs(int i, int sum, vector<int> &a, vector<vector<int>> &dp) {
    if (sum == 0) {
        return 1;
    }
    if (i == 0) {
        return sum % a[0] == 0;
    }
    if (dp[i][sum] != -1) {
        return dp[i][sum];
    }
    int pick = 0;
    if (sum >= a[i]) {
        pick = dfs(i, sum - a[i], a, dp);
    }
    int notPick = dfs(i - 1, sum, a, dp);
    return dp[i][sum] = pick + notPick;
}

void solve() {
    int MOD = 1000000007;
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
    }
    vector<vector<int>> dp(n, vector<int>(s + 1, 0));
    for (int i = 0; i < n; ++i) {
        dp[i][0] = 1;
    }
    for (int sum = 0; sum <= s; ++sum) {
        dp[0][sum] = sum % a[0] == 0;
    }
    for (int i = 1; i < n; ++i) {
        for (int sum = 1; sum <= s; ++sum) {
            int pick = sum >= a[i] ? dp[i][sum - a[i]] : 0;
            int notPick = dp[i - 1][sum];
            dp[i][sum] = (pick + notPick) % MOD;
        }
    }
    cout << dp[n - 1][s] << '\n';
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