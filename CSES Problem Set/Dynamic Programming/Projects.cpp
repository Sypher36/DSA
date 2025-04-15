#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(3));
    for (int i = 0; i < n; ++i) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    sort(a.begin(), a.end(), [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });
    vector<int> jumps(n, 0);
    for (int i = 0; i < n; ++i) {
        int l = 1, h = n - i;
        int r = h;
        while (l <= h) {
            int mid = (l + h) / 2;
            int idx = i + mid;
            if (idx == n || a[idx][0] > a[i][1]) {
                r = mid;
                h = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        jumps[i] = r;
    }
    vector<long long> dp(n + 1, 0);
    for (int i = n - 1; i >= 0; --i) {
        long long pick = a[i][2] + dp[i + jumps[i]];
        long long notPick = dp[i + 1];
        dp[i] = max(pick, notPick);
    }
    cout << dp[0] << '\n';
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