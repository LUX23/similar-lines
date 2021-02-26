/*
���� ������������� ������� A ������� M*N,
�������� ������� ����� ��������� �������� �� 0 �� 100.
����� ���������� ����� �������, ������� �� ������.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <conio.h>

int main()
{
    setlocale(LC_CTYPE,"RUSSIAN");
    srand(time(NULL));

    int M, N, c; // c - ���������� ������� �����
    printf("\t�������� ������� �������� M*N.\n");

    printf("\n������� �������� M: ");
    scanf("%d", &M);

    while (M <= 0) // �������� �� ������������� ��������
    {
        printf("\n������� ������������� �������� M! ");
        scanf("%d", &M);
    }

    printf("\n������� �������� N: ");
    scanf("%d", &N);

    while (N <= 0) // �������� �� ������������� ��������
    {
        printf("\n������� ������������� �������� N! ");
        scanf("%d", &N);
    }

    int A[M][N];
    printf("\n\t������� �������� �������:");
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
           printf("\n������� %d-� ������ %d-� �������: ", i+1, j+1);
           scanf("%d", &A[i][j]); // A[i][j] = rand()%101;
        }
    }

    printf("\n\t�������:\n");
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("\t%d ", A[i][j]);
        }
        printf("\n");
    }

    c = count(M, N, A);
    printf("\n\n������� �����: %d", c);

    getch();
    return 0;
}
