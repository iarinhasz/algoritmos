#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;


// Definição da estrutura de dados para a tabela de dispersão
typedef struct node{
    char* key;
    int value;
    struct node *next;
} HashNode;

typedef struct {
    int size;
    int count;
    HashNode** nodes;
} HashTable;

// Função de hashing simples que retorna um índice a partir da chave
int hash_function(char* key, int size) {
    int sum = 0;
    for (int i = 0; i < strlen(key); i++) {
        sum += key[i];
    }
    return sum % size;
}

// Função para inicializar a tabela de dispersão
HashTable* hash_init(int size) {
    HashTable* table =(HashTable*) malloc(sizeof(HashTable));
    table->size = size;
    table->count = 0;
    return table;
}

// Função para liberar a memória alocada pela tabela de dispersão
void hash_destroy(HashTable* table) {
    for (int i = 0; i < table->size; i++) {
        HashNode* node = table->nodes[i];
        if (node != NULL) {
            free(node->key);
            free(node);
        }
    }
    free(table->nodes);
    free(table);
}

// Função para inserir um elemento na tabela de dispersão
void hash_insert(HashTable* table, char* key, int value) {
    // Calcula o índice da chave na tabela
    int index = hash_function(key, table->size);

    // Verifica se já existe um nó com essa chave
    HashNode* node = table->nodes[index];
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            // A chave já existe, atualiza o valor
            node->value = value;
            return;
        }
        node = node->next;
    }

    // Cria um novo nó com a chave e o valor
    node = (HashNode*) malloc(sizeof(HashNode));
    node->key = strdup(key);
    node->value = value;

    // Insere o novo nó no início da lista encadeada na posição index
    node->next = table->nodes[index];
    table->nodes[index] = node;

    // Incrementa o contador de elementos na tabela
    table->count++;
}

// Função para recuperar o valor associado a uma chave na tabela de dispersão
int hash_get(HashTable* table, char* key) {
    // Calcula o índice da chave na tabela
    int index = hash_function(key, table->size);

    // Percorre a lista encadeada na posição index procurando pelo nó com a chave
    HashNode* node = table->nodes[index];
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            // A chave foi encontrada, retorna o valor
            return node->value;
        }
        node = node->next;
    }

    // A chave não foi encontrada, retorna 0
    return 0;
}

int main(){

    HashTable *hash;
    char letra = 'A';
    int casos, operacoes;
    char ent[4], chave[100];
    scanf("%d", &casos);
    for(int i =0; i<casos; i++){
        scanf("%d", &operacoes);
        for(int j = 0; j<operacoes; j++){
            scanf(" %s %s", ent, chave);
            if(ent[0]==65){
                hash_insert(hash, chave, j);
            }
        }
    }

    return 0;
}


