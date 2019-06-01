#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define TAM 1000000

int v[TAM];
void vetorzao(int v[]){

    int i,y, x = 1;

    for (i = 0; i < TAM; i++){
        y = (rand()%10) + 1;
        x = x + y;
        v[i] = x;
    }
}

int buscaSeqVet(){
    int i,y,x = 1;
    int cont;
    int n;
    double tempoBusca;
    double pegaBusca = 0;

    vetorzao(v);

    clock_t c1,c2;
    float tempo;

    //busca sequencial
    for(cont = 1; cont <= 30; cont++){
        tempoBusca = 0;
        c1 = clock();
        n = (rand()%TAM);
        for (i = 0; i < TAM-1; i++){
            if (v[i] == n){
                printf("Elemento encontrado!\n");
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

typedef struct tipoDado{
    int num;
} tipoDado;

typedef struct tipoNo{
    tipoDado dado;
    struct tipoNo *prox;
}tipoNo;


typedef struct {
  tipoNo *prim;
  tipoNo *ult;
  int numElem;
} tipoLista;


void inserirElemento(tipoLista *Lista, tipoDado num){
  tipoNo *aux;

  aux = (tipoNo *) malloc (sizeof(tipoNo));
  if(Lista->ult){
    Lista->ult->prox = aux;
  }else{
    Lista->prim = aux;
  }
  aux->prox = NULL;
  aux->dado = num;
  Lista->ult = aux;
  Lista->numElem++;
}


void mostrarLista(tipoLista Lista) {

  tipoDado aux;
  while(Lista.prim) {
    aux = Lista.prim->dado;
    printf("(%d)\n ", aux.num);
    Lista.prim = Lista.prim->prox;
  }
  printf("\n");
}

void criarLista(tipoLista *Lista) {
  Lista->prim= NULL;
  Lista->numElem = 0;
  Lista->ult = NULL;
}

void buscaSeq(tipoLista *Lista,tipoDado dado){
  tipoNo* aux;
  int chave;

  chave = dado.num;
  aux = Lista->prim;
  while(aux){
    if (aux->dado.num == chave){
      printf("Elemento encontrado!\n");
      break;
    }
    aux = aux->prox;
  }
}


void listaEncad(){
  int i,cont,n;
  double tempoBusca;
  double pegaBusca = 0;
  tipoLista L1;
  tipoDado dado;

  criarLista(&L1);

  vetorzao(v);

  for(i = 0; i < TAM; i++){
    dado.num = v[i];
    inserirElemento(&L1, dado);
   }

  clock_t c1,c2;
  float tempo;

  for(cont = 1; cont <= 30; cont++){
      tempoBusca = 0;
      c1 = clock();
      dado.num = (rand()%TAM);
      buscaSeq(&L1,dado);
      c2 = clock();

       tempoBusca = (c2 - c1)*1000 / (double)CLOCKS_PER_SEC;
       pegaBusca = pegaBusca + tempoBusca;
       printf("Tempo da busca %d: %f\n\n", cont, tempoBusca);
   }
   printf("Tempo medio: %f\n\n",(pegaBusca)/30);
}




int main() {

   printf("Busca Sequencial em lista encadeada com 1 milhao de elementos:\n\n");
   listaEncad();
   printf("\n//////////////////////////////////////////////////////////////////////////\n\n");
   printf("Busca Sequencial em vetor com 1 milhao de elementos:\n\n");
   buscaSeqVet();

}
