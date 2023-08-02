#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

//contar as casas q n sao alcancaveis a partir de (0,0)

const int MAXN = 11;

int rows[MAXN], cols[MAXN];

int bfs(int n) {
    int unreachable = 0;
    //mudancas de posicao
    int dr[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dc[] = {-1, 1, -2, 2, -2, 2, -1, 1};
    queue<pair<int, int>> q;
    
    //inicializando a matriz de visitados
    bool visited[n][n];
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (r == 0 && c == 0) continue;
            visited[r][c] = false;
        }
    }
    
    //agr que comeca a bfs
    q.push(make_pair(0, 0));    
    visited[0][0] = true;
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nr < n && nc >= rows[nr] && nc < rows[nr]+cols[nr] && !visited[nr][nc-rows[nr]]) {
                visited[nr][nc-rows[nr]] = true;
                q.push(make_pair(nr, nc-rows[nr]));
            }
        }
    }
    for (int r = 0; r < n; r++) {
        for (int c = rows[r]; c < rows[r]+cols[r]; c++) {
            if (!visited[r][c-rows[r]]) {
                unreachable++;
            }
        }
    }
    return unreachable;
}

int main() {
    int n;
    for (int t = 1; ; t++) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &rows[i], &cols[i]);
        }
        int unreachable = bfs(n);
        printf("Case %d, %d square", t, unreachable);
        if (unreachable == 1) {
            printf(" can not be reached.\n");
        } else {
            printf("s can not be reached.\n");
        }
    }
    return 0;
}