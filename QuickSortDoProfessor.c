#include <stdio.h>
#include <stdlib.h>

// Define uma constante
#define MAX 5

// Protótipo da função de ordenação
void quick_sort(int *a, int esquerda, int direita);

// Função main
int main()
{
    int i, vet[MAX];

    // Lê MAX
    for (i = 0; i < MAX; i++)
    {
        printf("Digite um valor: ");
        scanf_s("%d", &vet[i]);
    }

    // Ordena os valores
    quick_sort(vet, 0, MAX - 1);

    // Imprime os valores ordenados
    printf("\nValores ordenados\n");
    for (i = 0; i < MAX; i++)
    {
        printf(" %d -", vet[i]);
    }
    printf("\n\n\n\n");
    system("pause");
    return 0;
}

// Função de Ordenação por Seleção
void quick_sort(int *a, int esquerda, int direita) {
    int i, j, x, y;

    i = esquerda;
    j = direita;
    x = a[(esquerda + direita) / 2];

    while (i <= j) {
        while (a[i] < x && i < direita) {
            i++;
        }
        while (a[j] > x && j > esquerda) {
            j--;
        }
        if (i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }

    if (j > esquerda) {
        quick_sort(a, esquerda, j);
    }
    if (i < direita) {
        quick_sort(a, i, direita);
    }
}

