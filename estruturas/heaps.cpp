#include <stdio.h>
#include <stdlib.h>

#define MAX_N 5000

using namespace std;

// Define uma estrutura para um nó da Heap
typedef struct {
    int value;
} Node;

// Define uma Heap mínima de nós
typedef struct {
    Node *nodes[MAX_N]; // Vetor de nós da Heap
    int size; // Tamanho atual da Heap
} MinHeap;

// Inicializa uma Heap mínima vazia
MinHeap *initMinHeap() {
    MinHeap *heap = (MinHeap *) malloc(sizeof(MinHeap));
    heap->size = 0;
    return heap;
}
// Insere um nó na Heap
void insertNode(MinHeap *heap, Node *node) {
    // Insere o nó no final da Heap
    heap->nodes[heap->size] = node;
    heap->size++;

    // Restaura a ordem da Heap
    int current = heap->size - 1;
    while (current > 0 && heap->nodes[current]->value < heap->nodes[(current-1)/2]->value) {
        // Troca o nó com o seu pai
        Node *temp = heap->nodes[current];
        heap->nodes[current] = heap->nodes[(current-1)/2];
        heap->nodes[(current-1)/2] = temp;

        // Move para o pai
        current = (current-1)/2;
    }
}

// Remove o menor nó da Heap e o retorna
Node *removeMinNode(MinHeap *heap) {
    if (heap->size == 0) {
        return NULL;
    }

    // Remove o nó raiz
    Node *minNode = heap->nodes[0];
    heap->size--;

    // Substitui o nó raiz pelo último nó da Heap
    heap->nodes[0] = heap->nodes[heap->size];

    // Restaura a ordem da Heap
    int current = 0;
    while (current*2+1 < heap->size) {
        int left = current*2+1;
        int right = current*2+2;
        int smallest = left;

        if (right < heap->size && heap->nodes[right]->value < heap->nodes[left]->value) {
            smallest = right;
        }

        if (heap->nodes[current]->value > heap->nodes[smallest]->value) {
            // Troca o nó com o menor filho
            Node *temp = heap->nodes[current];
            heap->nodes[current] = heap->nodes[smallest];
            heap->nodes[smallest] = temp;

            // Move para o filho
            current = smallest;
        } else {
            break;
        }
    }

    return minNode;
}

int main() {
    int n;
    while (scanf("%d", &n) == 1 && n != 0) {
        // Cria uma Heap vazia
        MinHeap *heap = initMinHeap();
                // Insere os números na Heap
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);

            Node *node = (Node *) malloc(sizeof(Node));
            node->value = x;
            insertNode(heap, node);
        }

        // Realiza a soma dos números
        int cost = 0;
        while (heap->size > 1) {
            // Remove os dois menores números da Heap
            Node *node1 = removeMinNode(heap);
            Node *node2 = removeMinNode(heap);

            // Soma os valores dos nós
            int sum = node1->value + node2->value;
            cost += sum;

            // Cria um novo nó com a soma dos valores
            Node *newNode = (Node *) malloc(sizeof(Node));
            newNode->value = sum;

            // Insere o novo nó na Heap
            insertNode(heap, newNode);

            // Libera a memória dos nós antigos
            free(node1);
            free(node2);
        }

        // Imprime o custo total
        printf("%d\n", cost);

        // Libera a memória da Heap
        free(heap);
    }

    return 0;
}

