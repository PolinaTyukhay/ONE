#include <stdio.h>
#include <malloc.h>
#include <windows.h>
#include <locale.h>
#include <stdlib.h>

typedef struct
{
	int r;
	int c;
	int** matr;
}Matrix;

void MallocForAll(int*** matr, int row, int col)
{
	*matr = (int**)malloc(row * sizeof(int*));
	for (int i = 0; i < row; i += 1) {
		(*matr)[i] = (int*)malloc(col * sizeof(int));
	}

}
void FreeMemory(int*** matr, int* row) //������������ ������ 
{
	for (int i = 0; i < row; i++)
	{
		free((*matr)[i]);
	}
	free(*matr);
}
int check(char* NameFile, int* cnt_c, int* cnt_r)
{
	FILE* st;
	int cnt_t = 0, tst = 0, sym;
	*cnt_c = 0;
	*cnt_r = 0;
	errno_t err = fopen_s(&st, NameFile, "r");
	if (err)
	{
		printf("�������� � �������� �  %s: %d\n", NameFile, errno);

		return 0;
	}
	if (fopen_s(&st, NameFile, "r") != 0)
	{
		printf("������ �������� ����� %s: %d\n", NameFile, errno);
		return 0;
	}
	do
	{
		sym = fgetc(st);// ����������� ��������� � ��������
		if ((sym >= 'A') && (sym <= 'z') || (sym >= 128) && (sym <= 241))
		{
			printf("� ����� %s ������������ ������������ �������\n", NameFile);
			fclose(st);
			return 0;
		}
		if (sym == '\n' && *cnt_c > 0)//������� ������� ��������� �������� � ������ ����� 
		{
			*cnt_r = *cnt_r + 1;//���� ������
			if (cnt_t > 0 && cnt_t != *cnt_c)//�������� �� ������������ �������
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
		else if ((sym >= '0' && sym <= '9') || sym == '-' || sym == '+')//���� �������� 
		{
			if (tst == 0)
			{
				tst = 1;
				*cnt_c = *cnt_c + 1;//���� �������� 
			}
			else if (sym == '-' || sym == '+')
			{
				printf("���� \"%c\" ����������� ������ � ������ �����  ", sym);
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
}
int ProblemWithMAtrix(Matrix m)
{
	if ((m.r == 0) && (m.c == 0))
	{
		printf("������ ����");
		return (0);
	}
	if (m.r != m.c)
	{
		printf("������� �� ���������� , ���������� ����� ������������ ");
		return (0);
	}
}
void PrintMatr(int** matr, int r)// ���� �� ������� ��� ������ ?????
{
	for (int i = 0; i <r ; i++)
	{

		printf("\n");
		for (int j = 0; j < r; j++)
		{
			printf("%-3d ", matr[i][j]);
		}
	}
}
void FscanMatr(FILE* FF, Matrix k)
{
	for (int i = 0; i < k.r; i++)
	{
		for ( int j = 0; j < k.c; j++)
		{
			fscanf_s(FF, "%d\n", &k.matr[i][j]);
		}
	}
}
void JustScan(Matrix w)
{
	for (int i = 0; i < w.r; i++)
	{
		printf("������� %d ������ �������\n", i+1);
		for (int j = 0; j < w.c; j++)
		{
			scanf_s("%d", &w.matr[i][j]);
		}
	}
}
void Random(Matrix r)
{
	for (int i = 0; i < r.r; i++)
	{
		for (int j = 0; j < r.c; j++)
		{
			r.matr[i][j]= 1 + rand() % 100;
		}
	}
}
// ��������� ������� ��� i - � ������ � j - �� �������
void GetMatr(int** mas, int** p, int i, int j, int m)
{
	int ki, kj, di, dj;
	di = 0;
	for (ki = 0; ki < m - 1; ki++) { // �������� ������� ������
		if (ki == i) di = 1;
		dj = 0;
		for (kj = 0; kj < m - 1; kj++) { // �������� ������� �������
			if (kj == j) dj = 1;
			p[ki][kj] = mas[ki + di][kj + dj];
		}
	}
}
// ����������� ���������� ������������
int Determinant(int** mas, int m)
{
	int i, j, d, k, n;
	int** newmatr;
	MallocForAll(&newmatr, m,m);
	j = 0;
	d = 0;
	k = 1; //(-1) � ������� i
	n = m - 1; // ������� ������� ��� ������� � ������ 
	if (m < 1)
	{
		printf("��������� ������������� ����������");
	}
	if (m == 1)
	{
		d = mas[0][0];
		return(d);
	}
	if (m == 2)
	{
		d = mas[0][0] * mas[1][1]-(mas[1][0] * mas[0][1]);
		return(d);
	}
	if (m > 2)
	{
		for (i = 0; i < m; i++)
		{
			GetMatr(mas, newmatr, i, 0, m); 
			/*printf("\n%d", mas[i][j]);
			PrintMatr(newmatr, n);*/
			d = d + k * mas[i][0] * Determinant(newmatr, n);
			k = -k;
		}
	}
	return(d);
}

int main()  
{
	setlocale(LC_ALL, "rus");
	int i, j;
	int symA ; //row ������ col ������� 
	//��������� �������� 
	FILE* fA;
	Matrix M ;
	M.c = 0;
	M.r = 0;
	//��� ������ � ������
	/*int res = check("A.txt", &M.c, &M.r);
	if (res == 0)//������� �� ������ ��� ���������� �� ���� ���� � ��
	{
		exit(1);
	}
	fopen_s(&fA, "A.txt", "r");
	printf("cnt_row: %d cnt_col:%d\n", M.r, M.c);//row ������ col �������
	int emp= ProblemWithMAtrix(M);//���� � ����� ������ ��� ������� �� ����������
	if (emp == 0)
	{
		exit(1);
	}
	MallocForAll(&M.matr, M.r, M.c);*/
	//��� ������� ����� 
	/*int razm;
	printf("������� ������� ������� \n");
	scanf_s("%d", &M.r);
	if (M.r <= 0)
	{
		printf("��� �� �������");
		exit(1);
	}
	M.c = M.r;
	MallocForAll(&M.matr, M.r, M.c);*/
	
	//���������� � ������� 
	/*
	JustScan(M);
	*/
	//���������� ������� � ����� 
	/*
	FscanMatr(fA, M);
	*/
	// ��� ������� 
	srand(time(NULL));
	M.r =1+ rand()%10;
	M.c = M.r;
	printf("������� ������� %d", M.c);
	MallocForAll(&M.matr, M.r, M.c);
	//���������� ������� ��������� 
	
	Random(M);
	
	//�� ������ 
	printf("\n");
	PrintMatr(M.matr,M.r);
	printf("\n");
	int d;
	d = Determinant(M.matr,M.r);
	printf("\n������������ ������� ����� :%d", d);
	FreeMemory(&M.matr, M.r);
}
