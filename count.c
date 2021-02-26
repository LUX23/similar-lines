// —четчик похожих строк
#include <stdio.h>
#include <stdlib.h>

int count(int M, int N, int A[M][N])
{
    int size_first, size_next, // размеры множеств
                               // size_first - перва€ строка
                               // size_next - следующа€ строка
        c = 0, // количество похожих строк
        j;

    int* arr_first = NULL; // указатель первой строки
    int* arr_next = NULL; // указатель следующих строк

    arr_first = sort(&size_first, N, A[0]); // множество элементов первой строки

    printf("\n\t”пор€доченные строки:\n"
           "\t1: ");

    for (int i = 0; i < size_first; i++)
        printf("%d ", arr_first[i]);

    for (int i = 1; i < M; i++)
    {
        arr_next = sort(&size_next, N, A[i]); // множество элементов текущей строки
        printf("\n\t%d: ", i+1);

        for (j = 0; j < size_next; j++)
            printf("%d ", arr_next[j]);

        if (size_first == size_next) // если мощности множеств равны
        {
            for (j = 0; j < size_first; j++)
                if (arr_first[j] != arr_next[j]) // если элементы множеств не совпали
                    break;

            if (j == size_first) // если все элементы совпали
                c++;
        }
        free(arr_next); // освобождение пам€ти
    }

    free(arr_first); // освобождение пам€ти

    return c;
}
