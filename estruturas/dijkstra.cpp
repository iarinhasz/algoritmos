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

vector<int> dijkstra(int start) {
    vector<int> dist(graph.size(), INF);
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> fila;
    fila.push(make_pair(dist[start], start));

    //eqt n tiver vazia ok
    while(!fila.empty()){
        int u = fila.top().second;
        fila.pop();
        for(Edge& e : graph[u]){
            int v = e.to; //adj
            int weight = e.weight; //passando o tamanho ok
            //D[w] > D[v] + weight(G, v, w)
            if (dist[v] > dist[u] + weight) {
                //D[w] = D[v] + weight(G, v, w);
                dist[v] = dist[u] + weight;
                //insert(H, (v, w, D[w])); coloco na fila
                fila.push(make_pair(dist[v], v));
            }
        }
    }

    return dist;
}

int main() {

    int casos;
    scanf("%d", &casos);

    for (int k = 0; k < casos; k++){
        int vertices, arestas, s;
        scanf("%d %d", &vertices, &arestas);

        graph.clear();
        graph.resize(vertices);

        for (int i = 0; i < arestas; i++){
            int v1, v2, peso;
            scanf("%d %d %d", &v1, &v2, &peso);
            graph[v1].push_back(Edge(v2, peso)); // Aresta de v1 p v2 e seu peso
        }
        //origem dos caminhos de menor custo
        scanf("%d", &s);

        vector<int> dist = dijkstra(s);

        printf("Caso %d\n", k+1);
        for(int i = 0; i < vertices; i++){
            if(dist[i] == INF) printf("-1\n");
            else printf("%d\n", dist[i]);
        }
    }

    return 0;
}