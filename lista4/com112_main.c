#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "com112_sort.h"
#include "com112_sort.c"
//#include "com112_file.h"

void menu()
{
    int n = 0;
    printf("Escolha o tamanho do vetor que você deseja criar\n");
    scanf("%d", &n);

    int *v, i, vet[n];
        
    for (i = 0; i < n; i++)
    {
        vet[i] = rand() % 50;
    }

    printf("Vetor preenchido automaticamente:\n");
    printf("[");
    for (i = 0; i < n; i++)
    {
        printf(" %d", vet[i]);
    }
    printf(" ]\n\n");

    v = vet;

    int opc = 0;

    printf("Selecione o método de ordenação que deseja utilizar:\n");
    printf("Digite (1) para Bubble Sort\n");
    printf("Digite (2) para Selection Sort\n");
    printf("Digite (3) para Insertion Sort\n");

    scanf("%d", &opc);

    switch (opc)
    {
        case 1:
            bubble_sort(v, n);
            break;
                
        case 2:
            selection_sort(v, n);
            break;
                
        case 3:
            insertion_sort(v, n);
            break;
            
    }
}

int main()
{
    menu();
}

/*int relatorio()
    {

    }*/