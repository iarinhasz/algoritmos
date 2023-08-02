#include <iostream>
#include <stdlib.h>
using namespace std;
long long int particiona(long long int *v, long long int inicio, long long int final){
	long long int dir,esq,pivo,aux;
	esq=inicio;
	dir=final;
	pivo=v[inicio];
	while(esq<dir){ 
		while(v[esq]<=pivo){ //inverte aqui
			esq++;
		}
		while(v[dir]>pivo){ //inverte aqui
			dir--;
		}
		if(esq<dir){
			aux=v[esq];
			v[esq]=v[dir];
			v[dir]=aux;
		}
	}
	v[inicio]=v[dir];
	v[dir]=pivo;
	return dir;
}
void quicksort(long long int *v, long long int inicio, long long int fim){
	long long int pivo;
	if(fim>inicio){
		pivo=particiona(v,inicio, fim);
		quicksort(v,inicio,pivo-1);
		quicksort(v,pivo+1,fim);
	}
	
}
int main() {
	long long int t,check=0,op,qtd=0,i;
	bool flag=false;
	scanf("%lld",&t);
	long long int *arr=NULL;
	long long int value;
	
	while(check<t){
		scanf("%lld %lld",&op,&value);
		if(op==1){
			arr=(long long int *)realloc(arr,sizeof(long long int));
			arr[qtd]=value;
			qtd++;
			quicksort(arr,0,qtd-1);
		}
		else if(op==2){
			for(i=0;i<qtd;i++){
				if(value==arr[i]){
					printf("%lld\n",i+1);
					flag=true;
				}
			}
			if(!flag)printf("Data tidak ada\n");
			flag=false;
		}
	check++;	
	}
	free(arr);
	
	return 0;
}