#include <stdio.h>
#include <stdlib.h>
#include "revert.h"

int main() {
	int quantidade;
	printf("Quantidade de dados: ");
	while(scanf("%d",&quantidade) != 1) {
		scanf("%*[^\n]s\n");
		printf("Entrada invalida!\nQuantidade de dados: ");
	}
	int *num = (int*) calloc(quantidade,sizeof(int));
	if(num == NULL) {
		perror("main: ");
		exit(EXIT_FAILURE);
	}
	for(int i = 0; i < quantidade; i++) {
		printf("Numero %d: ",i+1);
		while(scanf("%d",&num[i]) != 1) {
			scanf("%*[^\n]s\n");
			printf("Entrada invalida!\nNumero %d: ",i+1);
		}
	}
	
	/**					Utilizando revertVector
		-Envolve menos passos, 
		-Porém o espaço é alocado dentro da função, logo não é tão intuitivo que
			free(*ptr) seja utilizado
		-A função pode envolver erros
		- Cada vez que a função é chamada, é alocado um espaço de memoria,
			facilitando que referências sejam perdidas
	**/
	int *revec = revertVector(num,quantidade);
	for(int i = 0; i < quantidade; i++)
		printf("%d ",revec[i]);
	printf("\n");
	//Lembrar de desalocar revec
	free(revec);	

	/**					Utilizando revertVector_
		-Envolve mais passos, 
		-O espaço é alocado onde a função é chamada, logo é intuitivo que
			free(*ptr) seja utilizado
		-Possiveis erros são tratados antes da chamada da função
	**/
	int *revec_ = (int*) calloc(quantidade,sizeof(int));
	if(revec_ == NULL) {
		perror("main: ");
		exit(EXIT_FAILURE);
	}
	revertVector_(revec_,num,quantidade);
	for(int i = 0; i < quantidade; i++)
		printf("%d ",revec_[i]);
	printf("\n");
	//Lembrar de desalocar revec_
	free(revec_);
	
	/** 				Parte comum 				**/
	free(num);
	return(0);
}
