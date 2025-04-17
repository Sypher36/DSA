#include <bits/stdc++.h>
using namespace std;

bool isValid(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void solve() {
    int n, m;
    cin >> n >> m;
    int dir[4][2] = {{-1, 0}, {+1, 0}, {0, -1}, {0, +1}};
    vector<vector<char>> a(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    int r = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '#') {
                continue;
            }
            r++;
            a[i][j] = '#';
            queue<pair<int, int>> q;
            q.push(make_pair(i, j));
            while (!q.empty()) {
                auto tp = q.front();
                int x = tp.first, y = tp.second;
                q.pop();
                for (int k = 0; k < 4; ++k) {
                    int nx = x + dir[k][0], ny = y + dir[k][1];
                    if (isValid(nx, ny, n, m) && a[nx][ny] == '.') {
                        a[nx][ny] = '#';
                        q.push(make_pair(nx, ny));
                    }
                }
            }
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