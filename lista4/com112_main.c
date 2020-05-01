//lista 4

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "com112_sort.h"
#include "com112_file.h"

void relatorio(double time, int comparison, int movement, int flag)
{
    if (flag == 0)
    {
        printf("Método Bubble Sort:\n");
    }
    else if(flag == 1){
        printf("Método Selection Sort:\n");
    }
    else{
        printf("Método Insertion Sort:\n");
    }
    
    printf("    Tempo de execução: %fs\n", time);
    printf("    Número de comparações: %d\n",comparison);
    printf("    Número de movimentações: %d\n", movement);
    printf("\n");
}

int menu()
{
    int opc;

    printf("Selecione o método de ordenação que deseja utilizar:\n");
    printf("Digite (1) para Bubble Sort\n");
    printf("Digite (2) para Selection Sort\n");
    printf("Digite (3) para Insertion Sort\n");

    scanf("%d", &opc);

    return opc;
}

void generateArray(int *array, int n){
    int i;

    for (i = 0; i < n; i++)
    {
        array[i] = rand() % 50;
    }
}


int main()
{
    int n, opc, flag;
    printf("Escolha o tamanho do vetor que você deseja criar\n");
    scanf("%d", &n);

    int vet[n];
    int dataArray[3];

    generateArray(vet, n);

    writeFile(n, vet, 0);
    opc = menu(n, vet);

    clock_t t;

    switch (opc)
    {
        case 1:
            flag = 0;
            t = clock();
            bubble_sort(vet, n, dataArray);
            t = clock() - t;
            break;
                
        case 2:
            flag = 1;
            t = clock();
            selection_sort(vet, n, dataArray);
            t = clock() - t;
            break;
                
        case 3:
            flag = 3;
            t = clock();
            insertion_sort(vet, n, dataArray);
            t = clock() - t;
            break;    
    }

    double time = ((double)t)/CLOCKS_PER_SEC;

    writeFile(n, vet, 1);

    writeReport(n, dataArray[0], dataArray[1], flag, time);

    relatorio(time, dataArray[0], dataArray[1], flag);
    
    return 0;

}