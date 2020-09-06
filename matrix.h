#pragma once
typedef struct
{
	int r;
	int c;
	int** matr;
}Matrix;
int** MallocForAll(int row, int col);
void  FreeMemory(int*** matr, int row);
int check(char* NameFile, int* cnt_c, int* cnt_r);
int ProblemWithMAtrix(Matrix m);
void PrintMatr(int** matr, int r);
void FscanMatr(FILE* FF, Matrix k);
void JustScan(Matrix w);
void Random(Matrix r);
void GetMatr(int** mas, int** p, int i, int j, int m);
int Determinant(int** mas, int m);
