#include<stdio.h>
#include<stdlib.h>
#include <queue>
#include<stack>
#define qtdNo 8
#define UNVISITED 0
#define VISITED 1

using namespace std;

typedef struct grafo{
    int numEdge;
    int *mark;
    int **matriz;
}grafo;

grafo *create_graph(int n){
    grafo *g = (grafo*) malloc(sizeof(grafo));
    g->matriz = (int**) malloc(sizeof(int*)*n);
    g->mark = (int*) malloc(sizeof(int)*n);
    if(g->matriz==NULL)exit(1);
    for(int i = 0; i<n; i++){
        g->matriz[i] = (int*) malloc (sizeof(int)*n);
        if(g->matriz[i]==NULL)exit(1);
    }
    g->numEdge = 0;
    return g;
}
int next(grafo *g, int v, int w, int n){ //procura o proximo vértice a partir de w... 
    for(int i=w+1;i<n-1;i++){
        if(g->matriz[v][i]!=0)return i;
    }
    return n;
}


int first(grafo *g, int v, int n){
    for(int i = 0; i<n-1;i++){
        if(g->matriz[v][i]!=0) return i;
    }
    return n;
}
void setEdge(grafo *g, int i, int j, int wt){
    if(wt == 0) printf("erro!\n");
    if(g->matriz[i][j] == 0) g->numEdge++;
    g->matriz[i][j] = wt;
}
void delEdge(grafo *g, int i, int j){
    if(g->matriz[i][j]!=0) g->numEdge--;
    g->matriz[i][j] = 0;
}
void setmark(grafo *g, int v, int val){
    g->mark[v] = val;
}

int getMark(grafo *g, int v){
    return g->mark[v];
}

/*traversia de grafos*/

void dfs(grafo *g, int v, int n){
    
   // printf("v = %d\n", v);
    setmark(g, v, VISITED);

    int w  = first(g, v, n);

    while(w<n){
        printf("%d ", w);
        if(getMark(g, w)== UNVISITED) dfs(g, w, n);
        w = next(g, v, w, n);
    }
    //printf("%d ", w);
}

void traversiaG(grafo *g, int n){
    for(int v = 0; v<n-1;v++){
        setmark(g, v, UNVISITED);
    }
    for(int v = 0; v < n-1; v++){
        if(getMark(g, v)==UNVISITED) dfs(g,v, n);
    }
}

void bfs(grafo *g, int start, int n, queue<int> fila){
    fila.push(start);
    //marco o vertice start como visitado
    setmark(g, start, VISITED);
    //percorrer todos os vertices, enquanto a fila nao esta vazia
    while(fila.size()>0){
        //removo o primeiro elemento da fila
        int v = fila.front();
        fila.pop();
        //encontro o primeiro vizinho do vertice 'v'
        int w = first(g, v, n);
        while(w<n){        
            printf("%d ", w);

            //se o vizinho w ainda nao foi visitado, marco como visitado
            if(getMark(g, w)==UNVISITED){
                setmark(g, w, VISITED);
                fila.push(w); //adiciono o vertice w na fila
            }
            //vou para o proximo vizinho
            w = next(g, v, w, n);
        }
    }
}

void toposort(grafo *g, stack<int> *s, int ind, int tam){
    if(getMark(g, ind)==UNVISITED){ 
        setmark(g, ind, VISITED);         
        int w = first(g, ind, tam);     
        printf("%d ", w);   
        while(w<tam){
            if(getMark(g, w)==UNVISITED) toposort(g, s, w, tam);
            w = next(g, ind, w, tam);             
        } 
        (*s).push(ind);      
    }
}
int main(){
    grafo *g = create_graph(qtdNo);
    setEdge(g,0,1,1);
    setEdge(g,0,2,1);
    setEdge(g,1,3,1);
    setEdge(g,3,4,1);
    setEdge(g,3,6,1);
    setEdge(g,2,5,1);
    setEdge(g,5,7,1);
    //visitando por dfs:
    /*dfs(g, 0, 8);
    queue<int> fila;
    bfs(g, 0, 8, fila);
    printf("\n");
    for(int i=0;i<qtdNo;i++){
        for(int j=0;j<qtdNo;j++){
            printf("%d ",g->matriz[i][j]);
        }
        printf("\n");
    }
    */
   stack<int> *s;
   toposort(g, s, 0, 8);

return 0;
}