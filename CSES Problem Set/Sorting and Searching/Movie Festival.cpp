#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n;
    cin >> n;
    vector<pair<long long, long long>> a(n);
    for (long long i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end(), [](const pair<long long, long long> &x, const pair<long long, long long> &y) {
        // return x.second == y.second ? x.first > y.first : x.second < y.second;
        return x.second < y.second; });
    long long r = 0;
    long long e = -1;
    for (long long i = 0; i < n; ++i) {
        if (a[i].first >= e) {
            ++r;
            e = a[i].second;
        }
    }
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