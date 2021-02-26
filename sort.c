// ���������� ��������
#include <stdio.h>
#include <stdlib.h>

int* sort(int *size, int N, int A[N]) // ���������� ��������� ��������� ������
{
    int i, j, temp, s; // temp - ��� ���������� ���������
                       // s - ������ �������
    s = 1;

    int* arr; // ��������� �� ������
    arr = (int*)malloc(s * sizeof(int)); // ��������� ������ ��� �������

    arr[0] = A[0];

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < s; j++)
        {
            if (A[i] == arr[j]) // ���� ������� ��� ��� �������
                break;
        }

        if (j == s) // ���� ������� ������� �� ��� ���� (���� ������ �� �����)
        {
            s = s + 1;
            arr = (int*)realloc(arr, s * sizeof(int)); // ��������� ������, � ����������
            arr[s - 1] = A[i];
        }
    }

    for (i = 0; i < s; i++)
        for (j = 0; j < s - 1; j++)
        {
            if (arr[j] > arr[j + 1]) // ���������� ���������
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }

    *size = s; // ������ ����������� �������

    return arr;
}

