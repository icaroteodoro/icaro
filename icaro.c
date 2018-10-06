
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct Carta{
	char nome[40];
	int k;
	int habilidade[50];
	char prox[40];

};


void alfabetica(struct Carta c[], int i, int x){
	if(i == x){
		return;
	}else{
		if(strcmp(c[i].nome, c[i+1].nome)<0){
			alfabetica(c,i+1,x);
		}else{
			struct Carta nova = c[i];
			c[i] = c[i+1];
			c[i+1] = nova;
			alfabetica(c,0, x);
		}
	}
}
void encontrar(struct Carta c[],char sorteado[], int i, int x, int j,int h){
	if(j == x){
		return;
	}else{
		if(strcmp(c[i].nome,sorteado)==0){
			printf("Indice %d", i);
			printf("Habilidade %d\n", c[i].habilidade[h%x]);
			strcpy(sorteado,c[i].prox);
			encontrar(c,sorteado,0,x,j+1,h+1);
		}else{
			encontrar(c,sorteado,i+1,x,j,h);
		}
	}
}
int main(){
	int a, i, j;

	scanf("%d", &a);

	struct Carta c[a];
	for(i = 0; i < a; i++){
		scanf("%s", c[i].nome);
		scanf("%d", &c[i].k);
		for(j = 0;j<c[i].k;j++){
			scanf("%d", &c[i].habilidade[j]);
		}
		scanf("%s", c[i].prox);
	}
	alfabetica(c,0,a);
	char sorteado[40];
	scanf("%s", sorteado);
	encontrar(c,sorteado,0,a,0,0);
	return 0;
}
