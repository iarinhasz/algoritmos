#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;
const int MAXM = 2e4 + 5;

struct Edge {
    int u, v, w;
    Edge() {}
    Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
    bool operator < (const Edge& e) const {
        return w < e.w;
    }
};

int parent[MAXN], rank_[MAXN];
Edge edges[MAXM], mst[MAXM];

int find(int u) {
    if (parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return;
    if (rank_[u] < rank_[v]) swap(u, v);
    parent[v] = u;
    if (rank_[u] == rank_[v]) rank_[u]++;
}

void kruskal(int n, int m) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank_[i] = 0;
    }
    sort(edges, edges + m);
    int mstSize = 0, mstCost = 0;
    for (int i = 0; i < m; i++) {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        if (find(u) == find(v)) {
            mst[mstSize++] = edges[i];
            mstCost += w;
            continue;
        }
        merge(u, v);
    }
    if (mstSize == 0) {
        cout << "forest" << endl;
        return;
    }
    bool hasCycle[MAXM] = {false};
    for (int i = 0; i < mstSize; i++) {
        for (int j = 0; j < n; j++) {
            parent[j] = j;
            rank_[j] = 0;
        }
        int cost = 0, cnt = 0;
        for (int j = 0; j < mstSize; j++) {
            if (i == j) continue;
            int u = mst[j].u, v = mst[j].v, w = mst[j].w;
            if (find(u) == find(v)) {
                hasCycle[j] = true;
            } else {
                merge(u, v);
                cost += w;
                cnt++;
            }
        }
        if (cnt == n - 1 && cost == mstCost) {
            hasCycle[i] = true;
        }
    }
    bool first = true;
    for (int i = 0; i < mstSize; i++) {
        if (hasCycle[i]) {
            if (!first) cout << " ";
            cout << mst[i].w;
            first = false;
            
        }
    }
    cout << endl;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            edges[i] = Edge(u, v, w);
        }
        kruskal(n, m);
    }
    return 0;
}