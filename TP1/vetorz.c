#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include <time.h>
#define TAM 1000000
int v[TAM];

void vetorzao(){
    int i,y, x = 1;

    for (i = 0; i < TAM-1; i++){
        y = (rand()%3) + 1;
        x = x + y;
        v[i] = x;
    }
}

int buscaBin(int n){
    int inicio,meio,fim;
    int cont;
    double tempoBusca;
    double pegaBusca = 0;

    vetorzao();

	clock_t c1,c2;
	float tempo;

    for(cont = 1; cont <= 30; cont++){
        tempoBusca = 0;
        inicio = 0;
        fim = TAM -1;
        c1 = clock();
        n = (rand()%TAM);
        while (inicio <= fim){
            meio = (inicio + fim)/2;

            if (v[meio] == n){
                printf("Elemento encontrado. -> ");
                break;
            }

            if (v[meio] < n) inicio = meio + 1;
            else fim = meio -1;
        }

        c2 = clock();

        tempoBusca = (c2 - c1)*1000 / (double)CLOCKS_PER_SEC;

        pegaBusca = pegaBusca + tempoBusca;

        printf("Tempo da busca %d: %f\n\n", cont, tempoBusca);

    }

    printf("Tempo medio: %f\n\n",pegaBusca/30);

    return 0;
}

int buscaSeq(int n){
    int i,y,x = 1;
    int cont;
    double tempoBusca;
    double pegaBusca = 0;

    vetorzao();

	clock_t c1,c2;
	float tempo;

    for(cont = 1; cont <= 30; cont++){
        tempoBusca = 0;
        c1 = clock();
        n = (rand()%TAM);

        for (i = 0; i < TAM-1; i++){

            if (v[i] == n){
                printf("Elemento encontrado! -> ");

                break;
            }
        }
        c2 = clock();

        tempoBusca = (c2 - c1)*1000 / (double)CLOCKS_PER_SEC;
        pegaBusca = pegaBusca + tempoBusca;
        printf("Tempo da busca %d: %f\n\n", cont, tempoBusca);
    }

    printf("Tempo medio: %f\n\n",pegaBusca/30);

    return 0;
}


int main(){
    int n;
    vetorzao();

    printf("Busca Sequencial em vetor com 1 milhao de elementos:\n\n");

    buscaSeq(n);

    printf("\n//////////////////////////////////////////////////////////////////////////\n\n");

    printf("Busca Binaria em vetor com 1 milhao de elementos:\n\n");

    buscaBin(n);
}
