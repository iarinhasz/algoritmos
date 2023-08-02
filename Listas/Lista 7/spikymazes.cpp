#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 42;
const int MAXJ = 21;
const int INF = 1e9;

int n, m, j;
char grid[MAXN][MAXN];
int dist[MAXN][MAXN][MAXJ];
int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

bool is_valid(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < m && grid[r][c] != '#';
}

bool is_exit(int r, int c, int k) {
    return grid[r][c] == 'x' && k >= 0;
}

int bfs(int sr, int sc) {
    queue<pair<int, pair<int, int>>> q;
    q.push({ sr, {sc, j} });
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k <= ::j; k++) {
                dist[i][j][k] = INF;
            }
        }
    }
    dist[sr][sc][j] = 0;
    while (!q.empty()) {
        auto [r, p] = q.front();
        auto [c, k] = p;
        q.pop();
        if (is_exit(r, c, k)) {
            return dist[r][c][k] + 1;
        }
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            int nk = k;
            if (grid[nr][nc] == 's') {
                nk--;
            }
            if (nk < 0) {
                continue;
            }
            if (is_valid(nr, nc) && dist[nr][nc][nk] == INF) {
                dist[nr][nc][nk] = dist[r][c][k] + 1;
                q.push({ nr, {nc, nk} });
            }
        }
    }
    return -1;
}

int main() {
    cin >> n >> m >> j;
    int sr, sc;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == '@') {
                sr = i;
                sc = j;
            }
        }
    }
    int ans = bfs(sr, sc);
    if (ans == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << "SUCCESS\n";
    }
    return 0;
}
