#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

const int INF = 0x3f3f3f3f; //numero "infinito"

struct Edge {
    int to, weight;
    Edge(int to, int weight) : to(to), weight(weight) {}
};

vector<vector<Edge>> graph;

int dijkstra(int start, int tar) {
    vector<int> dist(graph.size(), INF);
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> fila;
    fila.push(make_pair(dist[start], start));

    while(!fila.empty()){
        int u = fila.top().second;
        int c = fila.top().first;
        fila.pop();

        if(u == tar) return c;

        for(Edge& e : graph[u]){
            int v = e.to;
            int weight = e.weight;
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                fila.push(make_pair(dist[v], v));
            }
        }
    }

    return -1; //se o nó de destino não for alcançável
}
int main() {

    int casos;
    scanf("%d", &casos);
    
    int n, m, s, tar;

    for (int k = 0; k < casos; k++){
        scanf("%d %d %d %d", &n, &m, &s, &tar);

        graph.clear();
        graph.resize(n);

        for (int i = 0; i < m; i++){
            int v1, v2, peso;
            scanf("%d %d %d", &v1, &v2, &peso);
            graph[v1].push_back(Edge(v2, peso)); // Aresta de v1 p v2 e seu peso
            graph[v2].push_back(Edge(v1, peso));
        }

        int dist = dijkstra(s, tar);

        printf("Case #%d: ", k+1);
        int val = 0;
        if(dist == -1) printf("unreachable\n");
        else printf("%d\n", dist);

    }

    return 0;
}