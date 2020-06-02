#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "com112_sort.h"
#include "com112_file.h"

void escolha(int opcao, int *v, int n, int *comparacao, int *movimento)
{
    if(opcao == 1 || opcao == 6)
    {
        metodoBolha(v, n, comparacao, movimento);
    }
    else if(opcao == 2)
    {
        selection_sort(v, n, comparacao, movimento);
    }
    else if(opcao == 3)
    {
        insertion_sort(v, n, comparacao, movimento);
    }
    else if(opcao == 4)
    {
        int inicio = 0, fim = n-1;
        mergeSort(v, inicio, fim, comparacao, movimento);
    }
    else if(opcao == 5)
    {
        int inicio = 0, fim = n-1;
        quickSort(v, inicio, fim, comparacao, movimento);
    }
}

void metodoBolha(int *v,int n, int *comparacao, int *movimento)
{
    int aux;

    for(int j = 0; j < n; j++)
    {
        for(int i = 0; i < n-1-j; i++)
        {
            *comparacao = *comparacao + 1;
            if(v[i] > v[i+1])
            {
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                *movimento = *movimento + 1;
            }
        }
    }
}

void selection_sort(int *v, int n, int *comparacao, int *movimento)
{
    int menor, troca;
    for(int i = 0; i < n-1; i++)
    {
        menor = i;
        for(int j = i+1; j < n; j++)
        {
            *comparacao = *comparacao + 1;
            if(v[j] < v[menor])
            {
                menor = j;
            }
        }
        if(i != menor)
        {
            troca = v[i];
            v[i] = v[menor];
            v[menor] = troca;
            *movimento = *movimento + 1;
        }
        *movimento = *movimento + 1;
    }
}

void insertion_sort(int *v, int n, int *comparacao, int *movimento)
{
    int aux, j;
    for(int i = 1; i < n; i++)
    {
        aux = v[i];
        *comparacao = *comparacao + 1;
        for(j = i; (j > 0) && (aux < v[j - 1]); j--)
        {
            v[j] = v[j - 1];
            *movimento = *movimento + 1;
            *comparacao = *comparacao + 1;
        }
        v[j] = aux;
        *movimento = *movimento + 2;
    }
}

void merge(int *v, int inicio, int meio, int fim, int *comparacao, int *movimento)
{
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim-inicio+1;
    p1 = inicio;
    p2 = meio+1;
    temp = (int *) malloc(tamanho*sizeof(int));
    if(temp != NULL)
    {
        for(i=0; i<tamanho; i++)
        {
            if(!fim1 && !fim2)
            {
                *comparacao = *comparacao + 1;
                if(v[p1] < v[p2])
                {
                    *movimento = *movimento + 1;
                    temp[i]=v[p1++];
                }
                else
                {
                    *movimento = *movimento + 1;
                    temp[i]=v[p2++];
                }
                if(p1>meio)
                {
                    fim1=1;
                }
                if(p2>fim)
                {
                    fim2=1;
                }
            }
            else
            {
                if(!fim1)
                {
                    *movimento = *movimento + 1;
                    temp[i]=v[p1++];
                }
                else
                {
                    *movimento = *movimento + 1;
                    temp[i]=v[p2++];
                }
            }
        }
        for(j=0, k=inicio; j<tamanho; j++, k++)
        {
            v[k]=temp[j];
        }
    }
    free(temp);
}

void mergeSort(int *v, int inicio, int fim, int *comparacao, int *movimento)
{
    int meio;
    if(inicio < fim){
        meio = floor((inicio+fim)/2);
        mergeSort(v,inicio,meio, comparacao, movimento);
        mergeSort(v,meio+1,fim, comparacao, movimento);
        merge(v,inicio,meio,fim, comparacao, movimento);
    }
}

void troca(int *v, int i, int j, int *comparacao, int *movimento)
{
    int aux;
    aux = v[i];
    v[i] = v[j];
    v[j] = aux;
    *movimento = *movimento + 1;
}

int particiona(int *v, int inicio, int fim, int *comparacao, int *movimento)
{
    int pivo, i, j;
    pivo = v[(inicio + fim)/2];
    i = inicio - 1;
    j = fim + 1;
    while(i < j)
    {
            do
            {
                j = j - 1;
                *comparacao = *comparacao + 1;
            }
            while(v[j] > pivo);
            do
            {
                i = i + 1;
                *comparacao = *comparacao + 1;
            }
            while(v[i] < pivo);
            if(i < j)
            {
                troca(v, i, j, comparacao, movimento);
            }
    }
    return j;
}

void quickSort(int *v, int inicio, int fim, int *comparacao, int *movimento)
{
    int pivo;
    if(fim > inicio)
    {
        pivo = particiona(v, inicio, fim, comparacao, movimento);
        quickSort(v, inicio, pivo, comparacao, movimento);
        quickSort(v, pivo+1, fim, comparacao, movimento);
    }
}

void insercao_decrescente(int *v, int n)
{
    int aux, j;
    for(int i = 1; i < n; i++)
    {
        aux = v[i];
        for(j = i; (j > 0) && (aux > v[j - 1]); j--)
        {
            v[j] = v[j - 1];
        }
        v[j] = aux;
    }
}
