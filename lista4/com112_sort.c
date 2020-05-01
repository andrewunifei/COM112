#include <stdio.h>
#include <stdlib.h>
#include "com112_sort.h"

void bubble_sort (int *v, int n, int *r) 
{
    int i, k, j, aux, c = 0, t = 0;

    for (k = 1; k < n; k++) 
    {
        for (j = 0; j < n - 1; j++) 
        {
            if (v[j] > v[j + 1]) 
            {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
                t++;
            }
            c++;
        }
    }

    r[0] = c;
    r[1] = t;
}

void selection_sort(int *v, int n, int *r) 
{ 
    int i, j, menor, aux, c = 0, t = 0;

    for (i = 0; i < n - 1; i++)
    {
        menor = i;
        for(j = i + 1; j < n; j++)
        {
            if(v[j] < v[menor])
            {
                menor = j;
            }
            c++;
        }

        if(i != menor)
        {
            aux = v[i];
            v[i] = v[menor];
            v[menor] = aux;
            t++;
        }
        
    }

    r[0] = c;
    r[1] = t;
}

void insertion_sort(int *v, int n, int *r) 
{ 
    int i, k, j, aux, c = 0, t = 0; 

    for (k = 1; k < n; k++)
    { 
        aux = v[k];

        for (j = k; (j > 0) && (aux < v[j - 1]); j--)
        {
            v[j] = v[j - 1];
            t++;
        }
        v[j] = aux;
        c++;
        
    } 

    r[0] = c;
    r[1] = t;
}