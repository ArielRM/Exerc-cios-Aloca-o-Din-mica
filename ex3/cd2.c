//Código 2
#include <stdlib.h>
int main() {
	int *x = malloc(5); // Tipo de ponteiro inválido,
	// 		/\ Cast to (int*)
	x[5] = 3;	// x[5] fora da area alocada
	return 0;
}