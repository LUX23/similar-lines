#include <stdio.h>
#include <stdlib.h>

int* sort(int *size, int N, int A[N]) // сортировка множества элементов строки
{
    int i, j, temp, s; // temp - для сортировки пузырьком
                       // s - размер массива
    s = 1;

    int* arr; // указатель на массив
    arr = (int*)malloc(s * sizeof(int)); // выделение памяти для массива

    arr[0] = A[0];

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < s; j++)
        {
            if (A[i] == arr[j]) // если элемент уже был записан
                break;
        }

        if (j == s) // если элемент массива не был учтён (цикл прошел до конца)
        {
            s = s + 1;
            arr = (int*)realloc(arr, s * sizeof(int)); // выделение памяти с предыдущим
            arr[s - 1] = A[i];
        }
    }

    for (i = 0; i < s; i++)
        for (j = 0; j < s - 1; j++)
        {
            if (arr[j] > arr[j + 1]) // сортировка пузырьком
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }

    *size = s; // размер полученного массива

    return arr;
}

