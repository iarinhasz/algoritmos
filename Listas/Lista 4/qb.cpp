#include<stdio.h>
#include<stdlib.h>

using namespace std;

typedef struct link{
  int element;
  struct link *next;
} Link;
int glob = 0;
//criar no:
Link *create_link(int it, Link *nextval){
  Link *temp = (Link*) malloc (sizeof(Link));
  temp->element = it;
  temp->next = nextval;
  return temp;
}
Link *criar_link(Link *nextval){
  Link *temp = (Link*) malloc (sizeof(Link));
  temp->next = nextval;
  return temp;
}
typedef struct queue{
    Link *front;
    Link *rear;
    int size;
}Queue;

Queue *create_queue(){
    Queue *q = (Queue*) malloc(sizeof(Queue));
    q->front = criar_link(NULL);
    q->rear = q->front;
    q->size = 0;
    return q;
}

void enqueue(Queue *q, int it){
    q->rear->next = create_link(it, NULL);
    q->rear = q->rear->next;
    q->size++;
}
void dequeue(Queue *q){
    Link *temp = q->front->next;
    if(q->size == 0) return;
    q->front->next = q->front->next->next;
    if(q->front->next == NULL) q->rear = q->front;
    q->size--;
    free(temp);
}
int main(){
    Queue *q = create_queue();
    int entrada;
    while(scanf("%d", &entrada)){
        if(entrada == 0) break;
        int cont=0, som = 0;
        int vetor[entrada];
        for(int i = 0; i<entrada;i++){
            scanf("%d", &vetor[i]);
            cont += vetor[i];
            if(i > 0){
                enqueue(q, cont);   
            }
        }
        int aux = q->size;
        for(int j = 0; j<aux; j++){
            som += q->front->next->element;
            dequeue(q);
        }
        printf("%d\n", som);
    }
    free (q);
    return 0;
}