#include "soma.h"

int sumVector(int *vec, int N) {
	int soma = 0;
	for(int i  = 0; i < N ; i++)
		soma += vec[i];
	return(soma);
}