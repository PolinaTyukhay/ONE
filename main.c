﻿#include <stdio.h>
#include <malloc.h>
#include <windows.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"

/*typedef struct
{
	int r;
	int c;
	int** matr;
}Matrix;*/

/*int ** MallocForAll(int row, int col)
{
	int **matr = (int**)malloc(row * sizeof(int*));
	for (int i = 0; i < row; i += 1) {
		matr[i] = (int*)malloc(col * sizeof(int));
	}
	return(matr);
}
void  FreeMemory(int*** matr, int row) //освобождение памяти 
{
	for (int i = 0; i < row; i++)
	{
		free((*matr)[i]);
	}
	free(*matr);
}*/
/*int check(char* NameFile, int* cnt_c, int* cnt_r)
{
	FILE* st;
	int cnt_t = 0, tst = 0, sym;
	*cnt_c = 0;
	*cnt_r = 0;
	errno_t err = fopen_s(&st, NameFile, "r");
	if (err)
	{
		printf("проблемы с доступом к  %s: %d\n", NameFile, errno);

		return 0;
	}
	if (fopen_s(&st, NameFile, "r") != 0)
	{
		printf("ошибка открытия файла %s: %d\n", NameFile, errno);
		return 0;
	}
	do
	{
		sym = fgetc(st);// посимвольно считываем и прверяем
		if ((sym >= 'A') && (sym <= 'z') || (sym >= 128) && (sym <= 241))
		{
			printf("В файле %s присутствуют недопустимые символы\n", NameFile);
			fclose(st);
			return 0;
		}
		if (sym == '\n' && *cnt_c > 0)//считаем стрроки игнорируя переносы в начале файла 
		{
			*cnt_r = *cnt_r + 1;//счет строки
			if (cnt_t > 0 && cnt_t != *cnt_c)//проверка на заполненость матрицы
			{
				printf("Error: cnt col %d != %d\n", cnt_t, *cnt_c);
				fclose(st);
				return 0;

			}
			cnt_t = *cnt_c;
			tst = 0;
			//printf("cnt_c: %d\n",cnt_c); 
			*cnt_c = 0;
		}
		else if ((sym >= '0' && sym <= '9') || sym == '-' || sym == '+')//счет столбцов 
		{
			if (tst == 0)
			{
				tst = 1;
				*cnt_c = *cnt_c + 1;//счет столбцов 
			}
			else if (sym == '-' || sym == '+')
			{
				printf("знак \"%c\" допускается только в начале числа  ", sym);
				fclose(st);
				return 0;
			}

		}
		else if (sym == ' ')
		{
			tst = 0;
		}

	} while (sym != EOF); //
	if (tst == 1 || *cnt_c > 0)
	{
		*cnt_r = *cnt_r + 1;
	}
	fclose(st);
	return 1;
}*/
/*int ProblemWithMAtrix(Matrix m)
{
	if ((m.r == 0) && (m.c == 0))
	{
		printf("Пустой файл");
		return (0);
	}
	if (m.r != m.c)
	{
		printf("Матрица не квадратная , невозможно найти оперделитель ");
		return (0);
	}
}*/
/*void PrintMatr(int** matr, int r)// мжно ли сделать две скобки ?????
{
	for (int i = 0; i < r; i++)
	{

		printf("\n");
		for (int j = 0; j < r; j++)
		{
			printf("%-3d ", matr[i][j]);
		}
	}
}*/
/*void FscanMatr(FILE* FF, Matrix k)
{
	for (int i = 0; i < k.r; i++)
	{
		for (int j = 0; j < k.c; j++)
		{
			fscanf_s(FF, "%d\n", &k.matr[i][j]);
		}
	}
}*/
/*void JustScan(Matrix w)
{
	for (int i = 0; i < w.r; i++)
	{
		printf("введите %d сточку матрицы\n", i + 1);
		for (int j = 0; j < w.c; j++)
		{
			scanf_s("%d", &w.matr[i][j]);
		}
	}
}*/
/*void Random(Matrix r)
{
	for (int i = 0; i < r.r; i++)
	{
		for (int j = 0; j < r.c; j++)
		{
			r.matr[i][j] = 1 + rand() % 100;
		}
	}
}*/
// Получение матрицы без i - й строки и j - го столбца
/*void GetMatr(int** mas, int** p, int i, int j, int m)
{
	int ki, kj, di, dj;
	di = 0;
	for (ki = 0; ki < m - 1; ki++) { // проверка индекса строки
		if (ki == i) di = 1;
		dj = 0;
		for (kj = 0; kj < m - 1; kj++) { // проверка индекса столбца
			if (kj == j) dj = 1;
			p[ki][kj] = mas[ki + di][kj + dj];
		}
	}
}*/
// Рекурсивное вычисление определителя
/*int Determinant(int** mas, int m)
{
	long long d = 0;
	int i, j, k, n;
	//int** newmatr=MallocForAll(m, m);
	
	j = 0;
	d = 0;
	k = 1; //(-1) в степени i
	n = m - 1; // порадок матрици без столбца и срочки 
	if (m < 1)
	{
		printf("вычислить определитьель невозможно");
	}
	else if (m == 1)
	{
		d = mas[0][0];
		return(d);
	}
	else if (m == 2)
	{
		d = mas[0][0] * mas[1][1] - (mas[1][0] * mas[0][1]);
		return(d);
	}
	else
	{
		int** newmatr = MallocForAll(m, m);
		for (i = 0; i < m; i++)
		{
			GetMatr(mas, newmatr, i, 0, m);
			d = d + k * mas[i][0] * Determinant(newmatr, n);
			k = -k;
		}

		
		FreeMemory(&newmatr, m);
	}

	
	return(d);
}*/



int main()
{
	setlocale(LC_ALL, "rus");
	Matrix M;
	M.c = 0;
	M.r = 0;
	printf("для считывания матрицф из файла:1\nдля ввода данных с клавиатуры:2\nдля рандомной матрицы:3\n");
	int des;

	scanf_s("%d", &des);

	printf("ввели:%d\n", des);
	if (des == 1) {
		int i, j;
		int symA; //row строки col столбцы 
		//проверяем ошибочки 
		FILE* fA;
		//для работы с файлом
		int res = check("A.txt", &M.c, &M.r);
		if (res == 0)//поверка на ошибки при считывании по типу букв и тд
		{
			exit(1);
		}
		fopen_s(&fA, "A.txt", "r");
		printf("cnt_row: %d cnt_col:%d\n", M.r, M.c);//row строки col столбцы
		int emp= ProblemWithMAtrix(M);//если в файле ничего или матрица не квадратная
		if (emp == 0)
		{
			exit(1);
		}
		M.matr=MallocForAll(M.r, M.c);
		//считывание матрицы с файла 

		FscanMatr(fA, M);

	}
	else if (des == 2) {
		//для ручного ввода 
		int razm;
		printf("введите порядок матрицы \n");
		scanf_s("%d", &M.r);
		if (M.r <= 0)
		{
			printf("это не квадратная  матрица");
			exit(1);
		}
		M.c = M.r;
		M.matr=MallocForAll(M.r, M.c);

		//считвыание с консоли 
		
		JustScan(M);
		
	}
	else if (des == 3) {
		// для рандома 
		srand(time(NULL));
		M.r = 1 + rand() % 16;
		//M.r = 11;
		M.c = M.r;
		printf("порядок матрицы %d", M.c);
		M.matr = MallocForAll(M.r, M.c);
		//заполнение матрици рандомром 

		Random(M);
	}
	else {
		printf("ПОВТОРЯЮ:\nдля считывания матрицф из файла:1\nдля ввода данных с клавиатуры:2\nдля рандомной матрицы:3\n");
		exit(1);
	}
	//ее печать 
	printf("\n");
	PrintMatr(M.matr, M.r);
	printf("\n");
	time_t start, end;
	long long d;
	start = time(NULL);
	d = Determinant(M.matr, M.r);
	end = time(NULL);
	printf("\nопределитель матрицы равен :%d\n", d);
	printf("время затрачнное на вычисление: %0.1f", difftime(end, start));
	FreeMemory(&M.matr, M.r);
}
