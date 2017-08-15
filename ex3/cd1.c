//Código 1
#include <stdlib.h>
int main(void) {
	int *x = malloc(100); /** valgrind indicou erro aqui **/
	/** Correção
	free(x);
	**/
	return 0;
}

