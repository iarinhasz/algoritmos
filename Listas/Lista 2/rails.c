#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct {
    int id;
} Vagao;

typedef struct {
    int topo;
    Vagao dados[MAX];
} Pilha;

void empilha(Pilha *p, Vagao v) {
    p->dados[++p->topo] = v;
}

Vagao desempilha(Pilha *p) {
    return p->dados[p->topo--];
}

int ordenaVagoes(int *sequencia, int n) {
    int i, j, vagaoAtual;
    Pilha estacao, chegando;
    Vagao v;

    estacao.topo = -1;
    chegando.topo = -1;

    for (i = 0; i < n; i++) {
        v.id = sequencia[i];
        empilha(&chegando, v);
    }

    for (i = 1, vagaoAtual = 1; i <= n; i++) {
        if (estacao.topo >= 0 && estacao.dados[estacao.topo].id == vagaoAtual) {
            desempilha(&estacao);
            vagaoAtual++;
            i--;
        }
        else if (chegando.topo >= 0) {
            // Verifica se o proximo vagao da pilha de vagoes chegando eh o proximo a ser desempilhado
            while (chegando.topo >= 0 && chegando.dados[chegando.topo].id != vagaoAtual) {
                v = desempilha(&chegando);
                empilha(&estacao, v);
            }

            if (chegando.topo >= 0 && chegando.dados[chegando.topo].id == vagaoAtual) {
                // Desempilha o vagao da pilha de vagoes chegando
                desempilha(&chegando);
                vagaoAtual++;
            }
        }
    }

    if (estacao.topo < 0) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    int n, sequencia[MAX];

    while (1) {
        scanf("%d", &n);
        if (n == 0) {
            break;
        }

        for (int i = 0; i < n; i++) {
            scanf("%d", &sequencia[i]);
        }

        // Verifica se a sequência de vagoes pode ser ordenada
        if (ordenaVagoes(sequencia, n)) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
    }

    return 0;
}
