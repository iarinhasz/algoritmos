#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <string.h> 

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef map<string, int> msi;

void bfs(vvi& g, vi& dist, int s) {
    queue<int> q;
    q.push(s);
    dist[s] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : g[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vvi g(n);
        vs students;
        msi rank;

        for (int i = 0; i < n; i++) {
            string a, b, c;
            cin >> a >> b >> c;

            if (rank.find(a) == rank.end()) {
                rank[a] = students.size();
                students.push_back(a);
            }
            if (rank.find(b) == rank.end()) {
                rank[b] = students.size();
                students.push_back(b);
            }
            if (rank.find(c) == rank.end()) {
                rank[c] = students.size();
                students.push_back(c);
            }

            g[rank[a]].push_back(rank[b]);
            g[rank[b]].push_back(rank[a]);
            g[rank[a]].push_back(rank[c]);
            g[rank[c]].push_back(rank[a]);
            g[rank[b]].push_back(rank[c]);
            g[rank[c]].push_back(rank[b]);
        }

        int s = rank["Ahmad"];
        vi dist(n, -1);
        bfs(g, dist, s);

        cout << students.size() << endl;

        for (int i = 0; i < students.size(); i++) {
            cout << students[i] << " ";
            if (dist[i] == -1) {
                cout << "undefined" << endl;
            } else {
                cout << dist[i] << endl;
            }
        }
    }

    return 0;
}
