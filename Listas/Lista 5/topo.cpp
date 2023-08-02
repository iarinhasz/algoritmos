#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 10005;

int n, m;
vector<int> adj[MAXN];
int in_deg[MAXN];
bool vis[MAXN];
vector<int> order;

bool topological_sort() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in_deg[i] == 0) {
            q.push(i);
            vis[i] = true;
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (int v : adj[u]) {
            in_deg[v]--;
            if (in_deg[v] == 0 && !vis[v]) {
                q.push(v);
                vis[v] = true;
            }
        }
    }
    return (order.size() == n);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        in_deg[y]++;
    }
    if (topological_sort()) {
        for (int i = 0; i < n; i++) {
            cout << order[i];
            if (i != n-1) cout << " ";
        }
        cout << "\n";
    } else {
        cout << "Sandro fails.\n";
    }
    return 0;
}
