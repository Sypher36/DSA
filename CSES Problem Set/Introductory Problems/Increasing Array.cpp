#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x : a) {
		cin >> x;
	}
	long long r = 0;
	for (int i = 1; i < n; ++i) {
		if (a[i] < a[i - 1]) {
			r += 1LL * a[i - 1] - a[i];
			a[i] = a[i - 1];
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