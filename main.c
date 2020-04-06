#include <stdio.h>
#include <malloc.h>
#include <windows.h>
#include <locale.h>

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
void PrintMatr(Matrix p)
{
	for (int i = 0; i <p.r ; i++)
	{
		printf("\n");
		for (int j = 0; j < p.c; j++)
		{
			printf("%-3d ", p.matr[i][j]);
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
	}*/
	//��� ������� ����� 
	int razm;
	printf("������� ������� ������� \n");
	scanf_s("%d", &M.r);
	MallocForAll(&M.matr, M.r, M.c);
	M.c = M.r;
	//���������� � ������� 
	JustScan(M);

	//���������� ������� � ����� 
	/*
	FscanMatr(fA, M);
	*/
	//�� ������ 
	PrintMatr(M);
}
