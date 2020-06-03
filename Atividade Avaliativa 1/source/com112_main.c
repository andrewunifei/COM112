#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "com112_sort.h"
#include "com112_file.h"

clock_t options(int opc, int* Array, int length, int* dataArray){
    clock_t t;

    switch (opc)
    {
        case 0:
            t = clock();
            bubble_sort(Array, length, dataArray);
            t = clock() - t;
            break;
                
        case 1:
            t = clock();
            selection_sort(Array, length, dataArray);
            t = clock() - t;
            break;
              
        case 2:
            t = clock();
            insertion_sort(Array, length, dataArray);
            t = clock() - t;
            break;

        case 3:
            t = clock();
            merge_sort(Array, 0, length - 1, dataArray);
            t = clock() - t;
            break;
        
        case 4:
            t = clock();
            quick_sort(Array, 0, length - 1, dataArray);
            t = clock() - t;
            break;
    }

    return t;
}


void relatorio(double time, int comparison, int movement, int flag)
{
    if (flag == 0)
    {
        printf("Método Bubble Sort:\n");
    }
    else if(flag == 1){
        printf("Método Selection Sort:\n");
    }
    else if(flag == 2){
        printf("Método Insertion Sort:\n");
    }
    else if(flag == 3){
        printf("Método Merge Sort:\n");
    }
    else{
        printf("Método Quick Sort:\n");
    }
    
    printf("    Tempo de execução: %fs\n", time);
    printf("    Número de comparações: %d\n",comparison);
    printf("    Número de movimentações: %d\n", movement);
    printf("\n\n");
}

void reverse(int arr[], int n)
{
	int aux[n];

	for (int i = 0; i < n; i++) {
		aux[n - 1 - i] = arr[i];
	}

	for (int i = 0; i < n; i++) {
		arr[i] = aux[i];
	}
}

void copyArray(int *Array, int *copiedArray, int length){
    int i;
    for(i = 0; i < length; i++){
        copiedArray[i] = Array[i];
    }
}

void resetDataArray(int* dataArray){
    dataArray[0] = 0;
    dataArray[1] = 0;
}

void report(int length, int* dataArray){
        clock_t t;
        int Array[length], i, flag, secondFlag, copiedArray[length];
        
        for(flag = 0; flag < 3; flag++){
            secondFlag = 0;

            // As seguintes condicionais estão determinando qual arquivo será lido para
            // construir o Array. No primeiro loop, a flag é igual a 0, isso significa que temos 
            // um array ordenado aleatorimente, pois na função readFile, quando a flag é
            // igual a zero, ele apenas lê o com112_entrada.txt, como o habitual.
            // Quando flag == 1, a função readFile irá ler o arquivo com112_saida.txt,
            // isto é, um array ordenado de forma crescente. Já com flag = 2, o array
            // lido também é o ordenado, porém uma função intermediaria "reverse", reverte
            // o array ordenado de forma crescende, deixando ele ordenado de forma decrescente.
            // Portanto, uma escolhida a opção 6 no menu, os métodos de ordenação irão ordernar
            // um Array das três formas requisitadas no PDF, sem a necessidade de fazer isso manualmente.

            if(flag == 0){
                printf("Aleatório ==================================\n\n");
                readFile(Array, length, flag);
            }
            else if(flag == 1){
                printf("Crescente ===================================\n\n");
                readFile(Array, length, flag);
            }
            else if(flag == 2){
                printf("Decrescente =================================\n\n");
                flag = 1;
                readFile(Array, length, flag);
                reverse(Array, length);
                flag = 2;
            }
            
            ////////////////////////////////////////////////////////////////////////////////////

            for(i = 0; i < 5; i++){
                copyArray(Array, copiedArray, length);

                if(i == 0){
                    t = options(i, copiedArray, length, dataArray);
                }
                else if(i == 1){
                    t = options(i, copiedArray, length, dataArray);
                }
                else if(i == 2){
                    t = options(i, copiedArray, length, dataArray);
                }
                else if(i == 3){
                    t = options(i, copiedArray, length, dataArray);
                }
                else{
                    t = options(i, copiedArray, length, dataArray);

                    secondFlag = 1;
                }

                double time = ((double)t)/CLOCKS_PER_SEC;
                relatorio(time, dataArray[0], dataArray[1], i); // i aqui está se comportando como uma flag
                writeReport(length, dataArray[0], dataArray[1], i, secondFlag, flag, time);
                // A função resetDataArray é necessária para evitar o acumulo
                // de comparações e movimentações de diferentes métodos de ordenação
                resetDataArray(dataArray);
            }

            writeFile(length, copiedArray, 1);
        }
}

int menu()
{
    int opc;

    printf("Selecione o método de ordenação que deseja utilizar:\n");
    printf("Digite (1) para Bubble Sort\n");
    printf("Digite (2) para Selection Sort\n");
    printf("Digite (3) para Insertion Sort\n");
    printf("Digite (4) para Merge Sort\n");
    printf("Digite (5) para Quick Sort\n");
    printf("Digite (6) para gerar relatório\n");
    printf("Digite (7) para sair\n");

    scanf("%d", &opc);

    return opc;
}

void generateArray(int *array, int n){
    int i;

    srand(time(NULL));
    for (i = 0; i < n; i++)
    {
        array[i] = rand() % 50;
    }
}


int main()
{
    int n, opc, flag;
    double* time;
    clock_t t;

    printf("Entre com o tamanho do vetor que você deseja criar\n");
    scanf("%d", &n);

    int vet[n], aux[n], dataArray[2];

    generateArray(aux, n);

    writeFile(n, aux, 0);

    int true = 1;
    while(true){
        resetDataArray(dataArray);
        
        opc = menu();
        opc--;
        flag = opc;

        // para nao perder o vetor desordenado
        copyArray(aux, vet, n);

        if(opc != 5){
            t = options(opc, vet, n, dataArray);
        }
        else{
            report(n, dataArray); 
        }

        if(opc <= 4){
            double time = ((double)t)/CLOCKS_PER_SEC;

            writeFile(n, vet, 1);

            writeReport(n, dataArray[0], dataArray[1], flag, 2, 3, time);

            relatorio(time, dataArray[0], dataArray[1], flag);

        }
        else if(opc == 5){
            printf("\n");
            printf("Ordenação realizada com SUCESSO!\n\n");

        }
        else{
            return 0;
        }
    }
}
