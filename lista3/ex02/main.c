#include <stdio.h>
#include <stdlib.h>

typedef struct worker{
    char name[10];
    int salary[1];
}worker;

void *selectionSort(worker *array, int length, int flag){ 
    //flag irá ditar se a ordenação será alfabética ou por salário

    int i, j, k, min, aux;
    char aux2[10];

    for (i = 0; i < length - 1; i++)
    {
        min = i;

        if(flag == 1){
            for (j = i + 1; j < length; j++)
            {
                if (array[j].salary[0] > array[min].salary[0])
                { 
                    min = j;
                } 
            }
        }
        else{
            for (j = i + 1; j < length; j++)
            {
                if (array[j].name[0] < array[min].name[0])
                { 
                    min = j;
                } 
            }
        }

        if(min != i){
            aux = array[i].salary[0];
            for (k = 0; k < 10; k++)
            {
                aux2[k] = array[i].name[k];
            }

            array[i].salary[0] = array[min].salary[0];
            for (k = 0; k < 10; k++)
            {
                array[i].name[k] = array[min].name[k];
            }

            array[min].salary[0] = aux;
            for (k = 0; k < 10; k++)
            {
                array[min].name[k] = aux2[k];
            }
                
        }
            
    }  
}

void enterData(worker *instances, int length){
    int i;

    for (i = 0; i < length; i++)
    {
        printf("Entre com o nome do funcionario: ");
        scanf("%s", instances[i].name);

        printf("Entre com o salário: ");
        scanf("%d", instances[i].salary);

        printf("\n");
    }
    
}

int main(){
    //Para não ficar muito cansativo entrar com os valores, é possível mudar a variável
    //"quantity" para um valor menor que 10 (qualquer valor, na verdade)
    //essa variável representa a quantidade de instancias da struct "worker",
    //isto é, a quantidade de funcionários. O padrão é 10, como requisitado no exercício

    int quantity = 10;
    int i, flag;

    worker instances[quantity];

    enterData(instances, quantity);
    printf("\n");

    printf("A ordenação será por salário ou alfabética?\n");
    printf("Digite 0 para ordenação alfabética!\n");
    printf("Digite 1 para ordenação por salário decrescente!\n");
    printf(">>> ");
    scanf("%d", &flag);

    while(flag != 0 && flag != 1){
        printf("Por favor, entre com 0 ou 1!");
        scanf("%d", &flag);
    }

    printf("\n");

    if(flag == 1){
        printf("Antes da ordenação por salário: \n");
    }
    else{
        printf("Antes da ordenação por ordem alfabética: \n");
    }
    

    for (i = 0; i < quantity; i++)
    {
        printf("nome: %s    Salário: R$%d\n", instances[i].name, instances[i].salary[0]);
    }

    selectionSort(instances, quantity, flag);
    printf("\n");

    if(flag == 1){
        printf("Depois da ordenação por salário: \n");
    }
    else{
        printf("Depois da ordenação por ordem alfabética: \n");
    }

    for (i = 0; i < quantity; i++)
    {
        printf("nome: %s    Salário: R$%d\n", instances[i].name, instances[i].salary[0]);
    }

    printf("\n");
    
    return 0;
}