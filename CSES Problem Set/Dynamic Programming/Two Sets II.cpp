#include <bits/stdc++.h>
using namespace std;

int dfs(int i, int sum, vector<vector<int>> &dp) {
    if (i == 0) {
        return sum == 0;
    }
    if (dp[i][sum] != -1) {
        return dp[i][sum];
    }
    int pick = 0;
    if (sum >= i) {
        pick = dfs(i - 1, sum - i, dp);
    }
    int notPick = dfs(i - 1, sum, dp);
    return dp[i][sum] = pick + notPick;
}

void solve() {
    long long MOD = 1000000007 * 2;
    long long n;
    cin >> n;
    long long tsum = (n * (n + 1)) / 2;
    if ((tsum & 1) == 1) {
        cout << "0\n";
        return;
    }
    vector<vector<long long>> dp(n + 1, vector<long long>(tsum / 2 + 1, 0));
    dp[0][0] = 1;
    for (long long i = 1; i <= n; ++i) {
        for (long long sum = 0; sum <= (tsum >> 1); ++sum) {
            long long pick = 0;
            if (sum >= i) {
                pick = dp[i - 1][sum - i];
            }
            long long notPick = dp[i - 1][sum];
            dp[i][sum] = (pick + notPick) % MOD;
        }
    }
    long long r = dp[n][tsum >> 1] / 2;
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