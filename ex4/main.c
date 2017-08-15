#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main() {
	mat m1,m2;
	
	do {
		printf("Tamanho da matriz1 (linhas,colunas): ");
		if(scanf("%d,%d",&m1.row,&m1.col) == 2)
			break;
		scanf("%*[^\n]s");
		printf("Entrada inválida!\n");
	} while(1);
	m1.data = (int*) calloc (m1.col*m1.row,sizeof(int));
	if(m1.data == NULL) {
		perror("main :");
		exit(EXIT_FAILURE);
	}
	
	do {
		printf("Tamanho da matriz2 (linhas,colunas): ");
		if(scanf("%d,%d",&m2.row,&m2.col) == 2)
			break;
		scanf("%*[^\n]s");
		printf("Entrada inválida!\n");
	} while(1);
	m2.data = (int*) calloc (m2.col*m2.row,sizeof(int));
	if(m2.data == NULL) {
		perror("main :");
		exit(EXIT_FAILURE);
	}
	
	for(int i = 1; i <= m1.row; i++) {
		for(int j = 1; j <= m1.col; j++) {
			do {
				printf("Matriz1[%d,%d]: ",i,j);
				if(scanf("%d",getElement(&m1,i,j)) == 1)
					break;
				scanf("%*[^\n]s");
				printf("Entrada inválida!\n");
			} while(1);
		}
	}
	printMatrix(&m1);
	
	for(int i = 1; i <= m2.row; i++) {
		for(int j = 1; j <= m2.col; j++) {
			do {
				printf("Matriz2[%d,%d]: ",i,j);
				if(scanf("%d",getElement(&m2,i,j)) == 1)
					break;
				scanf("%*[^\n]s");
				printf("Entrada inválida!\n");
			} while(1);
		}
	}
	printMatrix(&m2);
	
	mat res;
	int hold = multMatrix(&m1,&m2,&res);
	
	switch(hold) {
		case 0:
			printf("Erro ao alocar memoria para res\n");
			break;
		case -1:
			printf("Dimensões inválidas\n");
			break;
		default:
			printf("Matriz1 * Matriz2 =\n");
			printMatrix(&res);
			free(res.data);
	}
	free(m1.data);
	free(m2.data);	
	return(0);
}