//bubble sort

#include <stdio.h>
#include <stdlib.h>

int *bubbleSort(int *v, int length){
    int i, aux, flag = 1;

    while(flag == 1)
    {
        flag = 0;

        for (i = 0; i < (length - 1); i++)
        {
            if (v[i] < v[i + 1])
            {
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                flag = 1;
            }
            
        }
        
    }
    
    return v;
}

int main(){
    int i,  length = 0, v[10] = {5, 7, 3, 2, 4, 0, 1, 9, 8, 6};

    printf("Antes da ordenacao:\n");

    for(i = 0; i < 10; i++){
        printf("%d ", v[i]);
        length++;
    }

    printf("\n");
    printf("\n");

    bubbleSort(v, length);
    
    printf("Depois da ordenacao:\n");

    for(i = 0; i < 10; i++){
        printf("%d ", v[i]);
    }

    printf("\n");

    return 0;
}