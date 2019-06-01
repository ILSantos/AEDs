#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct arv{
    int info;
    struct arv* esq;
    struct arv* dir;
};

typedef struct arv Arv;

Arv* busca(Arv* r, int n){
    if(r == NULL){
        return NULL;
     }else if(r->info > n){
        return busca(r->esq,n);
     }else if(r->info < n){
        return busca(r->dir,n);
     }else{
        return r;
     }
}

Arv* criar(){
    
    return NULL;
}

Arv* insere(Arv* a, int n){
    if(a == NULL){
        a = (Arv*) malloc (sizeof(Arv));
        a->info = n;
        a->esq = a->dir = NULL;
    }else if(n < a->info){
        a->esq = insere(a->esq,n);
    }else{
        a->dir = insere(a->dir,n);
    }
      return a;
}

void imprimePreOrd(Arv* arv){

    if(arv){
        printf("%d\n\n", arv->info);
        imprimePreOrd(arv->esq);
        imprimePreOrd(arv->dir);
    }
}

void imprimeEmOrd(Arv* arv){

    if(arv){
        imprimeEmOrd(arv->esq);
        printf("%d\n\n", arv->info);
        imprimeEmOrd(arv->dir);
    }
}

void imprimePosOrd(Arv* arv){

    if(arv){
        imprimePosOrd(arv->esq);
        imprimePosOrd(arv->dir);
        printf("%d\n\n", arv->info);
    }
}

void main(){
    Arv* arvAED = criar();
    int incremento = 0;
    int i, x=1;

    for(i = 0; i < 10; i++){
        incremento = (rand()%3) + 1;
        x = x + incremento;
        arvAED = insere(arvAED, x);
    }
    
    printf("Pré Ordem:\n");
    imprimePreOrd(arvAED); 
    printf("\n");
    printf("Em Ordem:\n"); 
    imprimeEmOrd(arvAED);
    printf("\n");
    printf("Pós Ordem:\n");
    imprimePosOrd(arvAED);     
}
