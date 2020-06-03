#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct data{
    int length;
    int comparison;
    int movement;
    int flag;
    int secondFlag;
    double time;
}data;

void readFile(int *array, int length, int flag){
    FILE *file;

    if(flag == 0){
        file = fopen("com112_entrada.txt", "r");
    }
    else if(flag == 1){
        file = fopen("com112_saida.txt", "r");
    }
 
	int i, j, c;
 
	for(i = 0; i < length + 2; i++){
        c = fgetc(file);

        if(c == '\n'){
            for(j = 0; j < length; j++){
                fscanf(file, "%d ", &array[j]);
            }
        }
    }

	fclose(file);
}

void writeFile(int length, int *array, int flag){
    FILE *filep;
    
    if(flag == 0){
        filep = fopen ("com112_entrada.txt", "w");
    }
    else
    {
        filep = fopen ("com112_saida.txt", "w");
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

void copyReport(int flag){
    // Função para copiar informações de um arquivo auxiliar para o arquivo de relatorio.
    // Aleḿ disso, também copia so dados para os relatórios mais específicos, dependendo da ordenação do vetor

    FILE *fptr1, *fptr2; 
    char c; 

    fptr1 = fopen("aux.txt", "r");

    if(flag == 0){
        fptr2 = fopen("com112_relatorio_aleatorio.txt", "a");
    }
    else if(flag == 1){
        fptr2 = fopen("com112_relatorio_crescente.txt", "a");
    }
    else if(flag == 2){
        fptr2 = fopen("com112_relatorio_decrescente.txt", "a");
    }
    else{
        fptr2 = fopen("com112_relatorio.txt", "a");
    }

    c = fgetc(fptr1); 
    while (c != EOF) 
    { 
        fputc(c, fptr2); 
        c = fgetc(fptr1); 
    } 
  
    fclose(fptr1); 
    fclose(fptr2);
}

void writeReport(int length, int comparison, int movement, int flag, int secondFlag, int thirdFlag, double time){
    data *instance;
    instance = malloc(sizeof(data));

    instance->length = length;
    instance->comparison = comparison;
    instance->movement = movement;
    instance->flag = flag;
    instance->time = time;

    FILE *fp;

    fp = fopen("aux.txt", "w");

    fprintf(fp, "%s", "Número de elementos ordenados: ");
    fprintf(fp, "%d", instance->length);
    fprintf(fp, "%s", "\n");
    
    if(instance->flag == 0){
        fprintf(fp, "%s", "Método Bubble Sort");
        fprintf(fp, "%s", "\n");
    }
    else if (instance->flag == 1){
        fprintf(fp, "%s", "Método Selection Sort");
        fprintf(fp, "%s", "\n");
    }
    else if (instance->flag == 2){
        fprintf(fp, "%s", "Método Insertion Sort");
        fprintf(fp, "%s", "\n");
    }
    else if(instance->flag == 3){
        fprintf(fp, "%s", "Método Merge Sort");
        fprintf(fp, "%s", "\n");
    }
    else{
        fprintf(fp, "%s", "Método Quick Sort");
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
    
    if(secondFlag == 1){
        fprintf(fp, "%s", "=======================================");
    }
    else if(secondFlag == 2){
        fprintf(fp, "%s", "=======================================");
    }
   
    fprintf(fp, "%s", "\n");

    fclose(fp);
    free(instance);

    copyReport(3);

    if(thirdFlag != 3){
        copyReport(thirdFlag);
    }

    remove("aux.txt"); 
}