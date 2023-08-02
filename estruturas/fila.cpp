#include<stdio.h>
#include<stdlib.h>

using namespace std;

typedef struct link{
  int element;
  struct link *next;
} Link;
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
    Queue *temp = q;
    if(q->size == 0) return;
    q->front->next = q->front->next->next;
    if(q->front->next == NULL) q->rear = q->front;
    q->size--;
    free(temp);
}
int frontValue(Queue *q){
    if(q->size == 0){
        return (int)NULL;
    }
    return q->front->next->element;
}
int main(){
    Queue *q = create_queue();
    enqueue(q, 1);
    enqueue(q, 2);
    int x = frontValue(q);
    printf ("x = %d\n", x);
    free(q);
    return 0;
}