#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

void printMatrix(mat* m) {
	for(int i = 1; i <= m->row; i++) {
		for(int j = 1; j <= m->col; j++)
			printf("%d ",*getElement(m,i,j));
		printf("\n");
	}
}

int* getElement(mat *m,int i, int j) {
	if(m->row < i || m->col < j)
		return NULL;
	return m->data + ((m->col)*(i-1))+(j-1);
}

int multMatrix(mat *m1, mat* m2, mat *mresult) {
	if(m1->col != m2->row)
		return -1;
	mresult->row = m1->row;
	mresult->col = m2->col;
	mresult->data = (int*) calloc(mresult->row * mresult->col, sizeof(int));
	if(mresult->data == NULL)
		return 0;
	for(int i = 1; i <= mresult->row; i++) {
		for(int j = 1; j <= mresult->col; j++) {
			for(int m = 1; m <= m1->col; m++)
				*getElement(mresult,i,j) += *getElement(m1,i,m) * *getElement(m2,m,j);
		}
	}
	return 1;
}
	