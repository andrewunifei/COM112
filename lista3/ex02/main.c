#include <stdio.h>
#include <stdlib.h>

typedef struct worker{
    char name[10];
    int salary[1];
}worker;

void *selectionSort(worker *array, int length, int flag){ 
    //flag irá ditar se a ordenação será crescente ou decrescente

    int i, j, k, min, aux;
    char aux2[10];

    for (i = 0; i < length - 1; i++)
    {
        min = i;
        for (j = i + 1; j < length; j++)
        {
            if(flag == 0){
                if (array[j].salary[0] < array[min].salary[0])
                { 
                    min = j;
                }
            }
            else{
                if (array[j].salary[0] > array[min].salary[0])
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
    }
    
}

int main(){
    int i, quantity = 3;
    worker instances[quantity];

    enterData(instances, quantity);
    printf("\n");

    printf("Antes da ordenação por salário: \n");

    for (i = 0; i < quantity; i++)
    {
        printf("nome: %s    Salário: R$%d\n", instances[i].name, instances[i].salary[0]);
    }

    selectionSort(instances, quantity, 1);
    printf("\n");
    printf("Depois da ordenação por salário: \n");

    for (i = 0; i < quantity; i++)
    {
        printf("nome: %s    Salário: R$%d\n", instances[i].name, instances[i].salary[0]);
    }

    printf("\n");
    
        
}