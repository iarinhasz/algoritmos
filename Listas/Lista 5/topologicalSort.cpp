#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 100005;

vector<int> graph[MAXN];
int inDegree[MAXN];
vector<int> sorted;

void toposort(int n) {
    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        sorted.push_back(u);

        for (auto v : graph[u]) {
            inDegree[v]--;

            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }
}

int main() {
    int n, m;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);

        graph[x].push_back(y);
        inDegree[y]++;
    }

    toposort(n);
    //a saida seria 1 4 3 5 7 8 2 6
    //primeiro teste
    if (sorted.size() == n) {
        for (auto v : sorted) {
            printf("%d ", v);
        }
    } else {
        printf("Sandro fails.");
    }

    cout << endl;

    return 0;
}



