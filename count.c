// ������� ������� �����
#include <stdio.h>
#include <stdlib.h>

int count(int M, int N, int A[M][N])
{
    int size_first, size_next, // ������� ��������
                               // size_first - ������ ������
                               // size_next - ��������� ������
        c = 0, // ���������� ������� �����
        j;

    int* arr_first = NULL; // ��������� ������ ������
    int* arr_next = NULL; // ��������� ��������� �����

    arr_first = sort(&size_first, N, A[0]); // ��������� ��������� ������ ������

    printf("\n\t������������� ������:\n"
           "\t1: ");

    for (int i = 0; i < size_first; i++)
        printf("%d ", arr_first[i]);

    for (int i = 1; i < M; i++)
    {
        arr_next = sort(&size_next, N, A[i]); // ��������� ��������� ������� ������
        printf("\n\t%d: ", i+1);

        for (j = 0; j < size_next; j++)
            printf("%d ", arr_next[j]);

        if (size_first == size_next) // ���� �������� �������� �����
        {
            for (j = 0; j < size_first; j++)
                if (arr_first[j] != arr_next[j]) // ���� �������� �������� �� �������
                    break;

            if (j == size_first) // ���� ��� �������� �������
                c++;
        }
        free(arr_next); // ������������ ������
    }

    free(arr_first); // ������������ ������

    return c;
}
