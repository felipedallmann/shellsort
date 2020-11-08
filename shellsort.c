#include <stdio.h>
#include <stdlib.h>
void insertionSort(int *V, int size);
void shellSort(int *V, int H, int size);

void insertionSort(int *V, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int i = 0; i < size; i++)
        {
            printf("array[%d]: %d | ", i, V[i]);
        }
        printf("\n");
        if (V[i] > V[i + 1])
        {
            int aux = V[i + 1];
            V[i + 1] = V[i];
            V[i] = aux;
        }

        for (int j = i; j > 0; j--)
        {
            if (V[j] < V[j - 1])
            {
                int aux = V[j];
                V[j] = V[j - 1];
                V[j - 1] = aux;
            }
        }
    }
}

void shellSort(int *V, int H, int size)
{
    printf("No shell:");
    for (int i = 0; i < size; i++)
    {
        printf("array[%d]: %d | ", i, V[i]);
    }
    printf("\n");
    if (H == 1)
    {
        insertionSort(V, size);
    }
    else
    {
        for (int i = 0; i < size - H; i++)
        {
            if (V[i] > V[i + H])
            {
                int aux = V[i];
                V[i] = V[i + H];
                V[i + H] = aux;
            }
        }
        shellSort(V, H - 1, size);
    }
}

int main()
{
    int vet[] = {4, 6, 1, 3, 7, 8, 5, 2, 9};
    int size = sizeof(vet) / sizeof(*vet);
    int H = (size - 1) / 2;
    for (int i = 0; i < size; i++)
    {
        printf("array[%d]: %d | ", i, vet[i]);
    }
    printf("\n");
    shellSort(vet, H, size);

    printf("ORDENADO:\n\n");
    for (int i = 0; i < size; i++)
    {
        printf("array[%d]: %d | ", i, vet[i]);
    }
    printf("\n");
}
