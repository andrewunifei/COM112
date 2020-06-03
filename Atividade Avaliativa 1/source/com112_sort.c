#include <stdio.h>
#include <stdlib.h>
#include "com112_sort.h"

void bubble_sort (int *v, int n, int *r) 
{
    int i, k, j, aux;
    long int c = 0, t = 0;

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
    int i, j, menor, aux;
    long int c = 0, t = 0;

    for (i = 0; i < n - 1; i++)
    {
        menor = i;
        for(j = i + 1; j < n; j++)
        {
            if(v[j] < v[menor])
            {
                menor = j;
                t++;
            }
            c++;
        }

        if(i != menor)
        {
            aux = v[i];
            t++;
            v[i] = v[menor];
            t++;
            v[menor] = aux;
            t++;
        }
        c++;
        
    }

    r[0] = c;
    r[1] = t;
}

void insertion_sort(int *v, int n, int *r) 
{ 
    int i, k, j, aux;
    long int c = 0, t = 0; 

    for (k = 1; k < n; k++)
    { 
        aux = v[k];

        for (j = k; (j > 0) && (aux < v[j - 1]); j--)
        {
            v[j] = v[j - 1];
            c++;
            t++;
        }
        v[j] = aux;
        c++;
        
    } 

    r[0] = c;
    r[1] = t;
}

void merge(int arr[], int l, int m, int r, int *info) 
{ 
    int i, j, k;
    long int c = 0, t = 0; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++){
        L[i] = arr[l + i]; 
    }
        
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1+ j]; 
    } 
        
    i = 0; 
    j = 0; 
    k = l;

    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++;
        } 
        else
        { 
            arr[k] = R[j]; 
            j++;
            t++; 
        } 
        k++;
        c++; 
    } 
  
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++;  
    } 
  
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++;
    }

    info[0] = c + info[0];
    info[1] = t + info[1]; 
} 

void merge_sort(int arr[], int l, int r, int *info) 
{ 
    if (l < r) 
    { 
        int m = l+(r-l)/2; 
  
        merge_sort(arr, l, m, info); 
        merge_sort(arr, m+1, r, info); 
  
        merge(arr, l, m, r, info); 
    } 
}

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

int partition (int arr[], int low, int high, int *info) 
{ 
    long int c = 0, t = 0;
    int pivot = arr[high];
    int i = (low - 1);
  
    for (int j = low; j <= high- 1; j++) 
    { 
        if (arr[j] < pivot) 
        { 
            i++;
            swap(&arr[i], &arr[j]);
            t++;
        }
        c++;
    } 
    swap(&arr[i + 1], &arr[high]);
    t++;

    info[0] = c + info[0];
    info[1] = t + info[1];
      
    return (i + 1); 
} 

void quick_sort(int arr[], int low, int high, int *info) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr, low, high, info); 
 
        quick_sort(arr, low, pi - 1, info); 
        quick_sort(arr, pi + 1, high, info); 
    } 
} 