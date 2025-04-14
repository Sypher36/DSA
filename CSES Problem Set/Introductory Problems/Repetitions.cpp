#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int r = 0;
    for (int i = 0; i < n; ++i) {
        int el = 1;
        while (i + 1 < n && s[i + 1] == s[i]) {
            ++el;
            ++i;
        }
        r = max(r, el);
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