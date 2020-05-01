//lista 4

#include <stdio.h>
#include <stdlib.h>

typedef struct data{
    int length;
    int comparison;
    int movement;
    int flag;
    double time;
}data;

void writeFile(int length, int *array, int flag){
    FILE *filep;
    
    if(flag == 0){
        filep = fopen ("com112_entrada.txt", "a");
    }
    else
    {
        filep = fopen ("com112_saida.txt", "a");
    }
    

    fprintf(filep, "%d", length);
    fprintf(filep, "%s", "\n");

    int i;

    for (i = 0; i < length; i++)
    {
        fprintf(filep, "%d", array[i]);
        fprintf(filep, "%c", 32);
    }

    fprintf(filep, "%s", "\n");

    fclose(filep);
}

void writeReport(int length, int comparison, int moviment, int flag, double time){
    data *instance;
    instance = malloc(sizeof(data));

    instance->length = length;
    instance->comparison = comparison;
    instance->movement = moviment;
    instance->flag = flag;
    instance->time = time;

    FILE *fp;

    fp = fopen("com112_relatorio.txt", "a");

    fprintf(fp, "%s", "Número de elementos ordenados: ");
    fprintf(fp, "%d", instance->length);
    fprintf(fp, "%s", "\n");
    
    if(instance->flag == 0){
        fprintf(fp, "%s", "Método Bubble Sort");
        fprintf(fp, "%s", "\n");
    }
    else if (instance->flag == 1){
        fprintf(fp, "%s", "Método Selectin Sort");
        fprintf(fp, "%s", "\n");
    }
    else{
        fprintf(fp, "%s", "Método Insertion Sort");
        fprintf(fp, "%s", "\n");
    }

    fprintf(fp, "%s", "    Tempo de execução: ");
    fprintf(fp, "%fs", instance->time);
    fprintf(fp, "%s", "\n");
    fprintf(fp, "%s", "    Número de comparações: ");
    fprintf(fp, "%d", instance->comparison);
    fprintf(fp, "%s", "\n");
    fprintf(fp, "%s", "    Número de movimentações: ");
    fprintf(fp, "%d", instance->movement);
    fprintf(fp, "%s", "\n");
   
    fprintf(fp, "%s", "\n");

    fclose(fp);
    free(instance);
}