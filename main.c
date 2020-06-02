#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "com112_sort.h"
#include "com112_file.h"

int menu();

void relatorio(double tempo, int movimento, int comparacao);

int main()
{
    int n, *v, opcao, movimento = 0, comparacao = 0;
    double tempo;
    clock_t inicio, fim;
    opcao = menu();
    while(opcao > 7 || opcao <= 0)
    {
        opcao = menu();
    }
    if (opcao == 7)
    {
        return 0;
    }
    printf("Digite o tamanho do vetor que se quer ordenar: ");
    scanf("%d", &n);
    v = (int *) malloc(n * sizeof(int));
    if(v == NULL)
    {
        printf("Erro: sem memória.\n");
        return 0;
    }
    srand(time(NULL));

    for(int i = 0; i < n; i++)
    {
        v[i] = rand() % 10000;
    }

    entrada(n, v);

    inicio = clock();
    escolha(opcao, v, n, &comparacao, &movimento);
    fim = clock();
    tempo = (double)(fim - inicio)*1000 / CLOCKS_PER_SEC;

    if(opcao != 6)
    {
        relatorio(tempo, movimento, comparacao);
    }

    saida(n, v);

    estatistica(opcao, v, n, tempo, movimento, comparacao);

    free(v);

    return 0;
}

int menu()
{
    int opcao;
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Merge Sort\n");
    printf("5. Quick Sort\n");
    printf("6. Relatório\n");
    printf("7. Sair\n");
    printf("Selecione uma opcao: ");
    scanf("%d", &opcao);

    return opcao;
}

void relatorio(double tempo, int movimento, int comparacao)
{
    printf("\n");
    printf("1. tempo de execução: %lf\n", tempo);
    printf("2. Número de comparações: %d\n", comparacao);
    printf("3. Numero de movimentacoes: %d\n", movimento);
}
