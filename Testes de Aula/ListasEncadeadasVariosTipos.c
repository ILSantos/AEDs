#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


/* Definicao de um novo tipo de dados para guardar informação na lista encadeada. Vamos começar colocando apenas duas informações numéricas.
Vamos supor que eu queira guardar um identificador numérico de pessoas e um score (alguma nota obtida, nao importa em que) associado a cada pessoa.
 */

typedef struct tipoDado {
  int id;
  float score;
}  tipoDado;


/* aqui criamos o tipoNo, que servirá para representar os elementos das 
nossas listas encadeadas */


typedef   struct tipoNo {
	   tipoDado dado;
       struct tipoNo *prox
}  tipoNo;

/*
  Aqui criamos um tipo para agregar todas as informações que preciso sobre a lista encadeada. Vamos criar 3 exemplos: tipoFila, tipoPilha e tipoLista. Notem que podemos representar as listas em varios casos sem ter uma struct para agregar informações. Não há padrão para seguir na implementação de listas */
 
/* tipoLista: vai conter informação sobre o primeiro da lista e o numero de elementos */

typedef struct {
  tipoNo *prim;
  int numElem;
} tipoLista;

/* tipoFila: Nas filas, é conveniente que eu tenha um ponteiro para o primeiro e um ponteiro para o último elemento. Pode-se colocar mais inforação de acordo com a necessidade da aplicação, incluindo-se coisas como tempo de espera na fila, tamanho corrente da fila e etc... Tudo que diz respeito à fila como um todo vem aqui */


typedef struct {
  tipoNo *prim;
  tipoNo    *ult;
} tipoFila;

/* tipoPilha: A pilha difere da lista pela maneira como inserimos elementos, pois sempre inserimos e removemos no começo da pilha. Geralmente chama-se o primeiro elemento de topo da pilha. */

typedef struct {
  tipoNo *topo;
} tipoPilha;

/******************************************************
Agora vamos fazer as funcoes básicas para manipular uma fila
Vamos dar nomes às funções descrevendo a ação no infinitivo
****************************************************/

/* Insere um elemento na fila apontada por F.
   Precisa do endereco da fila para realizar a operação porque pode 
modificar os valores de prim e ult */

  void inserirNaFila(tipoFila *fila, tipoDado d) {
    tipoNo *aux;

    aux = (tipoNo*) malloc(sizeof(tipoNo));  // crio um novo nó solto na memoria
    aux->dado = d;  // copio o dado para o nó
    aux->prox =NULL;  // faço o prox dele ser NULL (será o último da fila)
    
    if(fila->prim == NULL) { // aqui pergunto se a fila está vazia
      fila->prim = aux;  // se esta vazia, novo nó será o primeiro
    }
    else {
      fila->ult->prox= aux; // se nao está vazia, faz o último da lista apontar pra ele
    }
    fila->ult = aux; // aqui faz o novo nó ser também o último
  }




/******************************************************
Agora vamos fazer as funcoes básicas para manipular uma fila
Vamos dar nomes às funções descrevendo a ação no infinitivo
****************************************************/

/* Remove um elemento na fila apontada por F.
   Precisa do endereco da fila para realizar a operação porque pode 
modificar os valores de prim e ult 
  Tipicamente, a função de remoção retorna de algum modo o dado removido.
  Vamos assumir que NUNCA chamarao a funcao para remover de uma fila vazia!
*/

  tipoDado removerDaFila(tipoFila *fila) {
    tipoNo *aux;
    tipoDado d;

    //notem que nao vamos verificar se fila esta vazia.
    // Dará segfault caso alguem peça para remover de uma fila vazia!! 
    // Poderiamos proteger fazendo um teste.

      aux = fila->prim;  // aux usado para guardar temporariamente o prim
      d = aux->dado; // guarda o dado em d
      fila->prim = aux->prox; // move o ponteiro do primeiro para o próximo elemento
      free(aux); // libera memória do nó
      if(fila->prim == NULL) { 
	// Entrou aqui, significa que só tinha um elemento!
	fila->ult = NULL; // tenho que lembrar de deixar o ult com NULL
      }
    return d;
  }

/**************************************
  Uma última operação útil: uma função que retorne verdadeiro se há elementos na FILA, e retorne falso em caso contrário.
Antes de chamar a remocao da fila, deve-se usar essa funcao pra saber se ha elementos.
 Com isso, a funcao de cima nao precisa testar se ha elementos na FILA

****************************************/

tipoNo * haElementosNaFila(tipoFila fila) {

  return fila.prim;

}


/* Cria uma Fila vazia */


void criarFila(tipoFila *fila) {

  fila->prim = NULL;
  fila->ult = NULL;

}



/* Mostra os elementos atualmente na fila */

void mostrarFila(tipoFila fila) {
  
  while(fila.prim) {
    printf("(%d %.2f) ", fila.prim->dado.id,  fila.prim->dado.score);
    fila.prim = fila.prim->prox;
  }
  printf("\n");
}




/*************************************************************
Agora funcoes para inserir e remover de uma pilha
**************************************************************/


/* Remove um elemento na fila apontada por F.
   Precisa do endereco da fila para realizar a operação porque pode 
modificar os valores de prim e ult 
  Tipicamente, a função de remoção retorna de algum modo o dado removido.
  Vamos assumir que NUNCA chamarao a funcao para remover de uma fila vazia!
*/

  tipoDado removerDaPilha(tipoPilha *pilha) {
    tipoNo *aux;
    tipoDado d;

    //notem que nao vamos verificar se pilha esta vazia.
    // Dará segfault caso alguem peça para remover de uma pilha vazia!! 
    // Poderiamos proteger fazendo um teste.

      aux = pilha->topo;  // aux usado para guardar temporariamente o prim
      d = aux->dado; // guarda o dado em d
      pilha->topo = aux->prox; // move o topo
      free(aux); // libera memória do nó
    return d;
  }



void inserirNaPilha(tipoPilha *pilha, tipoDado d) {
    tipoNo *aux;
    

    aux = (tipoNo*) malloc(sizeof(tipoNo));  // crio um novo nó solto na memoria
    aux->dado = d;  // copio o dado para o nó
    aux->prox = pilha->topo;  // digo que depois dele vem o topo atual
    pilha->topo = aux;
}


/* Cria uma pilha vazia
 */

void criarPilha(tipoPilha *pilha) {

  pilha->topo = NULL;
}



tipoNo * haElementosNaPilha(tipoPilha pilha) {

  return pilha.topo;

}


/* para mostrar os elementos. Nao precisa de ponteiro para ponteiro porque nao queremos alterar o valor do ponteiro aqui. */

void mostrarPilha(tipoPilha pilha) {
  
  while(pilha.topo) {
    printf("(%d %.2f) ", pilha.topo->dado.id,  pilha.topo->dado.score);
    pilha.topo = pilha.topo->prox;
  }
  printf("\n");
}






/********************************************************
A partir de agora, as funçoes para listas encadeadas 
Em nosso exemplo, guardamos info sobre o numero de elementos da lista
*******************************************************/


void inserirElemento(tipoLista *L, tipoDado elemento) {
  tipoNo *aux;
  
  aux = (tipoNo *) malloc (sizeof(tipoNo));
  aux->prox = L->prim;
  aux->dado = elemento;
  L->prim = aux;
  L->numElem++;
}


/* para mostrar os elementos. Nao precisa de ponteiro para ponteiro porque nao queremos alterar o valor do ponteiro aqui. */

void mostrarLista(tipoLista L) {
  
  while(L.prim) {
    printf("(%d %.2f) ", L.prim->dado.id,  L.prim->dado.score);
    L.prim = L.prim->prox;
  }
  printf("\n");
}



void criarLista(tipoLista *L) {
  L->prim= NULL;
  L->numElem = 0;
}

int removerElementoDaLista(tipoLista *L, int chave) {
  tipoNo *aux,*tmp;

  if( L->prim)  {
    aux = L->prim;
    if(aux->dado.id == chave) {
      L->prim = aux->prox;   // (*p)->prox
      free(aux);
      L->numElem--;
      return 1;
    }
    else {
      while(aux->prox) {
	if(aux->prox->dado.id == chave) {
          tmp = aux->prox;
          aux->prox = tmp->prox;
          free(tmp);
	  L->numElem--;
          return 1;
	}
	aux= aux->prox;
      }
    }
  }
  return 0;
}


// FUNCAO MAIN APENAS PARA FAZER ALGUNS TESTES

int main() {
  tipoFila f1;
  tipoPilha p1;
  tipoDado d;
  
  // criar a fila e a pilha
   
  criarFila(&f1);
  criarPilha(&p1);
  
  d.id = 1; 
  d.score = 1.0;
  inserirNaFila(&f1,d);
  inserirNaPilha(&p1,d);
  
  d.id = 2; 
  d.score = 2.0;
  inserirNaFila(&f1,d);
  inserirNaPilha(&p1,d);
 
  d.id = 3; 
  d.score = 3.0;
  inserirNaFila(&f1,d);
  inserirNaPilha(&p1,d);
 

  d.id = 4; 
  d.score = 4.0;
  inserirNaFila(&f1,d);
  inserirNaPilha(&p1,d);


  // Vamos ver como estao as duas estruturas:

  printf("Veja a diferenca na fila e na pilha apos inserir 1, 2 3 e 4\n");

  printf("Dados da fila:");
  mostrarFila(f1);

  printf("Dados da pilha:");
  mostrarPilha(p1);

 d = removerDaFila(&f1);
 d = removerDaPilha(&p1);

 printf("Agora após remover um elemento de cada\n");
 printf("Dados da fila:");
 mostrarFila(f1);
 printf("Dados da pilha:");
 mostrarPilha(p1);

 printf("Agora vamos apagar todos os elementos da fila\n");

 while(haElementosNaFila(f1)) {
    d = removerDaFila(&f1);
    printf("removi o %d\n",d.id);
 }
 
 printf("Agora vamos apagar todos os elementos da pilha\n");

 while(haElementosNaPilha(p1)) {
    d = removerDaPilha(&p1);
    printf("removi o %d\n",d.id);
 }


}




  
