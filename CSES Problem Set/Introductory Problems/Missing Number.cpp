#include <bits/stdc++.h>
using namespace std;

void solve() {
	long long n;
	cin >> n;
	long long tSum = ((n + 1) * n) >> 1;
	for (int i = 1; i < n; ++i) {
		long long x;
		cin >> x;
		tSum -= x;
	}
	cout << tSum << '\n';
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