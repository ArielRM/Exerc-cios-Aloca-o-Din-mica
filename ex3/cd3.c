/**
	ESTE CODIGO NEM COMPILA
	x não foi declarado na função f
	
	Neste caso o erro seria desalocar uma memoria já desalocada
**/

//Código 3
#include <stdlib.h>
void f(void) {
	free(x);
}
int main(void) {
	int *x = malloc(100);
	f();
	free(x);
	return 0;
}