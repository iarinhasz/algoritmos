#include <iostream>
using namespace std;

void merge(int *vet, int left, int right, int *vetAux){
    for(int k = left; k <= right; k++){
        vetAux[k] = vet[k];
    }
    int meio = (left + right)/2;
    int i = left;
    int j = meio + 1;
    
    for(int atual = left; atual <= right; atual++){
        if(i == meio + 1){
            vet[atual] = vetAux[j];
            j++;
        }else if(j > right){
            vet[atual] = vetAux[i];
            i++;
        }else if(vetAux[i] <= vetAux[j]){
            vet[atual] = vetAux[i];
            i++;
        }else{
            vet[atual] = vetAux[j];
            j++;
        }
    }
}

void mergeSort(int *vet, int left, int right, int *vetAux){
    if(left < right){
        long long int meio = (left + right)/2;
        mergeSort(vet, left, meio, vetAux);
        mergeSort(vet, meio + 1, right, vetAux);
        merge(vet, left, right, vetAux);
    }
}
int main(){

    int qntChocolates, *barras;
    scanf("%d", &qntChocolates);
    //arrumando as barras
    barras = (int*) malloc (sizeof(int)*qntChocolates);
    for(int i = 0; i<qntChocolates;i++){
        scanf("%d", &barras[i]);
    }
    //printf("soma das barras: %d\n", somaBarras);
    //vetor auxiliar para mergesort:
    int *vet = (int*) malloc(sizeof(int)*qntChocolates);
    //agora ordeno os valores
    mergeSort(barras, 0, qntChocolates-1, vet);
    
    //agora os cupons:
    int qntCupons, cupons, soma = 0;
    scanf("%d", &qntCupons);
    
    for(int i = 0; i < qntCupons;i++){
        scanf("%d", &cupons);
        for(int j=0; j<cupons; j++){
            if(j<qntChocolates) soma+=barras[j];
        }
        printf("%d\n", soma);
    }
    free(barras);
    free(vet);

    return 0;
}