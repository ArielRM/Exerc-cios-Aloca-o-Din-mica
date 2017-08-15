#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED
struct _mat {
	int* data;
	int col;
	int row;
};
typedef struct _mat mat;
void printMatrix(mat* m1);
int* getElement(mat *m,int i, int j);
int multMatrix(mat *m1, mat* m2, mat *mresult);
#endif