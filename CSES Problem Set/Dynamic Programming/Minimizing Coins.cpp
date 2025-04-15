#include <bits/stdc++.h>
using namespace std;

int dfs(int i, int sum, vector<int> &a, vector<vector<int>> &dp) {
    if (i == 0) {
        if (sum % a[0] != 0) {
            return 100000000;
        }
        return sum / a[i];
    }
    if (dp[i][sum] != -1) {
        return dp[i][sum];
    }
    int pick = 100000000;
    if (sum >= a[i]) {
        pick = 1 + dfs(i, sum - a[i], a, dp);
    }
    int notPick = dfs(i - 1, sum, a, dp);
    return dp[i][sum] = min(pick, notPick);
}

void solve() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
    }
    vector<vector<int>> dp(n, vector<int>(s + 1, 100000000));
    for (int sum = 0; sum <= s; ++sum) {
        dp[0][sum] = sum % a[0] != 0 ? 100000000 : sum / a[0];
    }
    for (int i = 1; i < n; ++i) {
        for (int sum = 0; sum <= s; ++sum) {
            int pick = 100000000;
            if (sum >= a[i]) {
                pick = 1 + dp[i][sum - a[i]];
            }
            int notPick = dp[i - 1][sum];
            dp[i][sum] = min(pick, notPick);
        }
    }
    int r = dp[n - 1][s];
    if (r >= 100000000 || r <= 0) {
        cout << "-1\n";
    }
    else {
        cout << r << '\n';
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