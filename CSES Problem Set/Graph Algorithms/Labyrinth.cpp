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
    pair<int, int> st, end;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 'A') {
                st.first = i;
                st.second = j;
            }
            else if (a[i][j] == 'B') {
                end.first = i;
                end.second = j;
            }
        }
    }
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    queue<pair<int, int>> q;
    dist[st.first][st.second] = 0;
    q.push(make_pair(st.first, st.second));
    while (!q.empty()) {
        auto tp = q.front();
        q.pop();
        int x = tp.first, y = tp.second, w = dist[x][y];
        for (int k = 0; k < 4; ++k) {
            int nx = x + dir[k][0], ny = y + dir[k][1];
            if (isValid(nx, ny, n, m) && a[nx][ny] != '#' && w + 1 < dist[nx][ny]) {
                q.push(make_pair(nx, ny));
                dist[nx][ny] = w + 1;
            }
        }
    }
    if (dist[end.first][end.second] == INT_MAX) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    cout << dist[end.first][end.second] << '\n';
    string s = "";
    while (end != st) {
        int x = end.first, y = end.second;
        if (isValid(x - 1, y, n, m) && dist[x - 1][y] == dist[x][y] - 1) {
            end.first--;
            s.push_back('D');
        }
        else if (isValid(x + 1, y, n, m) && dist[x + 1][y] == dist[x][y] - 1) {
            end.first++;
            s.push_back('U');
        }
        else if (isValid(x, y - 1, n, m) && dist[x][y - 1] == dist[x][y] - 1) {
            end.second--;
            s.push_back('R');
        }
        else {
            end.second++;
            s.push_back('L');
        }
    }
    reverse(s.begin(), s.end());
    cout << s << '\n';
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