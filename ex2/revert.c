#include "revert.h"
#include <stdio.h>
#include <stdlib.h>

int* revertVector(int *vec, int N) {
	int* revec = (int*) calloc(N,sizeof(int));
	if(revec == NULL) {
		perror("revertVector: ");
		exit(EXIT_FAILURE);
	}
	for(int i = 0, j = N-1; i < N; i++,j--)
		revec[j] = vec[i];
	return(revec);
}

void revertVector_(int *revec, int *vec, int N) {
	for(int i = 0,j = N-1; i < N; i++,j--)
		revec[j] = vec[i];
}