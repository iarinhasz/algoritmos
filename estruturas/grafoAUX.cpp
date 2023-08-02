#include <iostream>
#include <stack>
#include <queue>
#define qtdNo 8
#define UNVISITED 0
#define VISITED 1
using namespace std;

typedef struct {
    int **matriz;
    int numEdge; // referente a arestas do grafo;
    int *Mark;

}G;
 // n=numero de vértices
G* create_graph(int n){
    G *g=(G*)malloc(sizeof(G));
    g->Mark=(int *)calloc(sizeof(int),n);
    g->matriz=(int **)calloc(sizeof(int *),n);
    if(g->matriz==NULL)exit(1);
    for(int i=0;i<n;i++){
        g->matriz[i]=(int *)calloc(sizeof(int),n);
        if(g->matriz[i]==NULL)exit(1);
    }
    g->numEdge=0;
    return g;
}

int first(G *g, int v, int n){ // encontra o 1° vértice ligado a o vertice passado como parametro
    for(int i=0;i<n-1;i++){
        if(g->matriz[v][i]!=0)return i;
    }
    return n;
}

int next(G *g, int v, int w, int n){ //procura o proximo vértice a partir de w... 
    for(int i=w+1;i<n-1;i++){
        if(g->matriz[v][i]!=0)return i;
    }
    return n;
}

// inserção e exclusão de arestas;

void setEdge(G *g, int i, int j, int wt){
    if(wt==0)printf("ERRO!");
    if(g->matriz[i][j]==0) g->numEdge++;
    g->matriz[i][j]=wt;
}
void delEdge(G *g, int i, int j){
    if(g->matriz[i][j]!=0)g->numEdge--;
    g->matriz[i][j]=0;
}
//checar se tem aresta em determinada posicao:

bool isEdge(G *g,int i, int j){
    if(g->matriz[i][j]!=0)return true;
    else return false;
}
int e(G *g){ //retorna o numero de arestas...
    return g->numEdge;
}
//retorna o que está na matriz no índice g[i][j];

int weight(G *g, int i, int j){
    return g->matriz[i][j];
}
void setmark(G *g, int v, int val){ // se ja visitou ou não certo vértice
    g->Mark[v]=val;
}
int getMark(G *g, int v){

    return g->Mark[v];
}


//...Maneiras classicas de varrer um grafo...
//DFS:
void  DFS( G *g, int v,int n){
    printf("%d",v);
    setmark(g,v,VISITED);
    int w=first(g,v,n);
    while(w<n){
        if(getMark(g,w)==UNVISITED){
            DFS(g,w,n);
        }
        w=next(g,v,w,n);
    }

}
void GraphTraverse(G *g, int n){
    
    for(int v=0;v<n-1;v++)setmark(g,v,UNVISITED);
    for(int v=0;v<n-1;v++){
        if(getMark(g,v)==UNVISITED){
            DFS(g,v,n);
        }
    }
}

void BFS(G *g, int v,int n){
    queue<int> q;
    q.push(v);
    setmark(g,v,VISITED);
    while(q.size()>0){
        v=q.front();
        q.pop();
        printf("%d ",v);
        int w=first(g,v,n);
        while(w<n){
            if(getMark(g,w)==UNVISITED){
                setmark(g,w,VISITED);
                q.push(w);
            }
            w=next(g,v,w,n);
        }
        
    }
}
void GraphTraverse_BFS(G *g, int n){
    for(int v=0;v<n-1;v++){
        setmark(g,v,UNVISITED);
    }
    for(int v=0; v<n-1;v++){
        if(getMark(g,v)==UNVISITED){
            BFS(g,v,n);
        }
    }
}

//Topological sorting:
void toposort(G *g, int v, stack<int>s, int n){
    setmark(g,v,VISITED);
    int w=first(g,v,n);
    while(w<n){
        if(getMark(g,w)==UNVISITED){
            toposort(g,w,s,n);
        }
        w=next(g,v,w,n);
    }
    s.push(v);
    while(!s.empty()){
        printf(" %d ",s.top());
        s.pop();
    }
}


int main(){
    G *g=create_graph(qtdNo);
    stack<int>pilha;
    setEdge(g,0,1,1);
    setEdge(g,0,2,1);
    setEdge(g,1,3,1);
    setEdge(g,3,4,1);
    setEdge(g,3,6,1);
    setEdge(g,2,5,1);
    setEdge(g,5,7,1);
    /*for(int i=0;i<qtdNo;i++){
        for(int j=0;j<qtdNo;j++){
            printf("%d ",g->matriz[i][j]);
        }
        printf("\n");
    }*/
    DFS(g,0,qtdNo);
    printf("\n");
    for(int i=0;i<qtdNo;i++){
        for(int j=0;j<qtdNo;j++){
            printf("%d ",g->matriz[i][j]);
        }
        printf("\n");
    }
    

    //toposort(g,3,pilha,qtdNo);
    /*bool status=isEdge(g,0,1);
    printf("Tem aresta? %d",status);
    printf("\npos remocao: \n");
    delEdge(g,0,1);
    for(int i=0;i<qtdNo;i++){
        for(int j=0;j<qtdNo;j++){
            printf("%d ",g->matriz[i][j]);
        }
        printf("\n");
    }
    status=isEdge(g,0,1);
    printf("Tem aresta? %d",status);*/
    
 
}