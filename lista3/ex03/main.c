//insertion sort

#include <stdio.h>
#include <stdlib.h>

typedef struct product
{
    int code[1];
    int price[1];
    char description[10];
}product;

void insertionSort(product *array, int length){
    int i, j, k, aux2, aux3;
    char aux[10];

    for(i = 1; i < length; i++){
        for (k = 0; k < 10; k++)
        {
            aux[k] = array[i].description[k];
            aux2 = array[i].code[0];
            aux3 = array[i].price[0];
        }

        for(j = i - 1; j >= 0 && (array[j].description[0] > aux[0]); j--){
            for (k = 0; k < 10; k++)
            {
                array[j + 1].description[k] = array[j].description[k];
            }
            array[j + 1].code[0] = array[j].code[0];
            array[j + 1].price[0] = array[j].price[0];
        }
        for (k = 0; k < 10; k++)
        {
            array[j + 1].description[k] = aux[k];
        }
        array[j + 1].code[0] = aux2;
        array[j + 1].price[0] = aux3;
    }
}

void enterData(product *instances, int length){
    int i;

    for (i = 0; i < length; i++)
    {
        printf("Entre com a descrição do produto: ");
        scanf("%s", instances[i].description);

        printf("Entre com o código do produto: ");
        scanf("%d", instances[i].code);

        printf("Entre o preço do produto: ");
        scanf("%d", instances[i].price);

        printf("\n");
    }
    
}

int main(){
    //Para não ficar muito cansativo entrar com os valores, é possível mudar a variável
    //"quantity" para um valor menor que 10 (qualquer valor, na verdade)
    //essa variável representa a quantidade de instancias da struct "product",
    //isto é, a quantidade de produtos. O padrão é 10, como requisitado no exercício

    int i, quantity = 10;
    product instances[quantity];

    enterData(instances, quantity);
    printf("\n");

    printf("Antes da ordenação: \n");

    for (i = 0; i < quantity; i++)
    {
        printf("Descrição: %s    Código: %d     Preço: %d\n",
        instances[i].description, instances[i].code[0], instances[i].price[0]);
    }

    insertionSort(instances, quantity);
    printf("\n");

    printf("Depois da ordenação: \n");

    for (i = 0; i < quantity; i++)
    {
        printf("Descrição: %s    Código: %d     Preço: %d\n",
        instances[i].description, instances[i].code[0], instances[i].price[0]);
    }

    return 0;
}