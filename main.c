/*
Дана целочисленная матрица A размера M*N,
элементы которой могут принимать значения от 0 до 100.
Найти количество строк матрицы, похожих на первую.
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

    int M, N, c; // c - количество похожих строк
    printf("\tСоздание матрицы размером M*N.\n");

    printf("\nВведите значение M: ");
    scanf("%d", &M);

    while (M <= 0) // проверка на положительное значение
    {
        printf("\nВведите положительное значение M! ");
        scanf("%d", &M);
    }

    printf("\nВведите значение N: ");
    scanf("%d", &N);

    while (N <= 0) // проверка на положительное значение
    {
        printf("\nВведите положительное значение N! ");
        scanf("%d", &N);
    }

    int A[M][N];
    printf("\n\tВведите значения матрицы:");
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
           printf("\nВведите %d-ю строку %d-й столбец: ", i+1, j+1);
           scanf("%d", &A[i][j]); // A[i][j] = rand()%101;
        }
    }

    printf("\n\tМатрица:\n");
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("\t%d ", A[i][j]);
        }
        printf("\n");
    }

    c = count(M, N, A);
    printf("\n\nПохожих строк: %d", c);

    getch();
    return 0;
}
