#include <stdio.h>
#include <stdlib.h>
#include "soma.h"

int main() {
	int tamanho;
	printf("Tamanho do vetor: ");
	while(scanf("%d",&tamanho) != 1) {
		scanf("%*[^\n]s\n");
		printf("Entrada invalida!\nTamanho do vetor: ");
	}
	int *num = (int*) calloc(tamanho, sizeof(int));
	if( num == NULL) {
		perror("main: ");
		exit(EXIT_FAILURE);
	}
	for(int i = 0; i < tamanho; i++) {
		printf("Numero %d: ",i+1);
		while(scanf("%d",&num[i]) != 1) {
			scanf("%*[^\n]s\n");
			printf("Numero %d: ",i+1);
		}
	}
	printf("Soma = %d\n",sumVector(num,tamanho));
	free(num);
	return(0);
}