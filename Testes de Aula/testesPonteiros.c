#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


// Definicao de um novo tipo de dados para guardar informação sobre pessoas 
// Veja que em uma struct posso misturar diferentes tipos de dados
// posso inclusive ter campos que sao outras structs, caso necessario

typedef struct tipoDadosDePessoas {
  char nome[30];
  int numInterno;
  char  cpf[15];
}  tipoDadosDePessoas ;


/* aqui criamos o tipoNo, que servirá para representar os elementos das nossas listas encadeadas */

typedef struct tipoNo {
  tipoDadosDePessoas dado;
  struct tipoNo *prox;
} tipoNo;



// nossa funcao para ler strings com seguranca
void lerString(char stringVar[], int tamanho) {


  fgets(stringVar,tamanho,stdin);
  if(stringVar[strlen(stringVar)-1] == '\n') {
    stringVar[strlen(stringVar)-1] = 0;
  }
 
}

// aqui uma funcao de comparacao de caracteres que foi usada em exemplo anterior.
// Nao sera usada aqui, mas vamos deixar o codigo assim mesmo.

int compara( char x, char y) {

  if ((x >= 65) && (x <= 90)) {
    x= x +32;
  }
  return x-y;
}


/* Busca Binaria, buscando pelo nome. Assumimos que o vetor esta ordenado pelo nome
   Note que ela nao serve para buscar na lista encadeada, servindo apenas para os vetores.
  Note de qq modo uma mudanca. Passei a usar o parametro v como ponteiro, ao inves de vetor.
*/

int buscaBinaria(tipoDadosDePessoas *v, int tam, char nome[]) {
  int meio,inicio=0, fim=tam-1;
  int tmp;

  while(inicio <= fim) {
    meio = (inicio + fim)/2;
    tmp = strcmp(nome, v[meio].nome);
    if(tmp > 0) {
      inicio = meio+1;
    }
    else if (tmp < 0) {
      fim = meio -1;
    }
    else {
      return meio;
    }
  }
  return -1;
}


// Faz o merge entre dois vetores ordenados, colocando o resultado em um terceiro vetor. Assume que o terceiro vetor é grande o suficiente para comportar todas as posicoes do merge

void merge(tipoDadosDePessoas v1[], 
	   int n1, 
	   tipoDadosDePessoas v2[], 
	   int n2, 
	   tipoDadosDePessoas v3[]) {
  int i= 0, j= 0;

  while((i < n1) && (j < n2) ) {
    if( strcmp( v1[i].nome, v2[j].nome) < 0) {
      v3[i+j] = v1[i];
      i++;
    }
    else {
      v3[i+j] = v2[j];
      j++;
    }
  }
  while(j < n2) { v3[i+j] = v2[j];  j++;  }
  while( i < n1) { v3[i+j] = v1[i]; i++; }
}


// Ordena o vetor pelo nome

  void ordenaInsercaoPeloNome(tipoDadosDePessoas  v[], int tamanho) {
    int i, j;
    tipoDadosDePessoas pivot;

    
    for(j = 1; j < tamanho; j++ ) {
      i = j -1;
      pivot = v[j];
    while(i>=0) {
      if(strcasecmp(v[i].nome,pivot.nome)>0) {
	v[i+1] = v[i];
      }
      else {
	break;
      }
      i--;
    }
    v[i+1] = pivot;
    }
  }

// ordena pelo CPF

  void ordenaInsercaoPeloCPF(tipoDadosDePessoas  v[], int tamanho) {
    int i, j;
    tipoDadosDePessoas pivot;

    
    for(j = 1; j < tamanho; j++ ) {
      i = j -1;
      pivot = v[j];
    while(i>=0) {
      if(strcasecmp(v[i].cpf,pivot.cpf)>0) {
	v[i+1] = v[i];
      }
      else {
	break;
      }
      i--;
    }
    v[i+1] = pivot;
    }
  }

void mostraPessoas(tipoDadosDePessoas v[],int tam) {
  int x;

  printf("****************************\n");
  for(x = 0; x< tam; x++) {
    printf("Nome: %s\nNumero Interno: %d\n",v[x].nome,v[x].numInterno);
    printf("----------------------------\n");
  }
  printf("****************************\n");
}


void preencheAleatoriamente(tipoDadosDePessoas v[], int tam) {
  int x,y;
  int tamString;
  char vogais[6]="aeiou";
  char consoantes[22]="bcdfghjklmnpqrstvxyzw";
  char numeros[10]="0123456789";

  for (x= 0; x < tam; x++) {
    tamString = rand() % 29;
    for(y = 0; y < tamString; y++) {
      if( y == 0) {
	v[x].nome[y] = consoantes[rand()%21]-32;
      }
      else if( (y % 2) == 0) {
	v[x].nome[y] = consoantes[rand()%21];
      }
      else {
	v[x].nome[y] = vogais[rand()%5];
      }

    }
    v[x].nome[y] = 0;
    v[x].numInterno = rand();
    // gera um CPF
    for (y= 0; y < 14; y++) {
      if((y == 3) || (y == 7) || (y == 11)) {
	 v[x].cpf[y] = '.';
      }
      else {
	v[x].cpf[y] = numeros[rand()%10];
      }
    }
     v[x].cpf[y] = 0;
  }
}

/********************************************************
A partir de agora, as funçoes para listas encadeadas */

/* para inserir um elemento na lista */

void insereElemento(tipoNo **p, tipoDadosDePessoas elemento) {
  tipoNo *aux;
  
  aux = (tipoNo *) malloc (sizeof(tipoNo));
  aux->prox = (*p);
  aux->dado = elemento;
  *p = aux;
}

/* Outro jeito de inserir elemento na lista. Dessa vez sem usar ponteiro para ponteiro. 


*/

tipoNo * insereElementoDeOutroJeito(tipoNo *p, tipoDadosDePessoas elemento) {
  tipoNo *aux;
  
  aux = (tipoNo *) malloc (sizeof(tipoNo));
  aux->prox = p;
  aux->dado = elemento;
  return aux;
}

/* para mostrar os elementos. Nao precisa de ponteiro para ponteiro porque nao queremos alterar o valor do ponteiro aqui. */

void mostraLista(tipoNo *p) {
  
  while(p) {
    printf("%s\n", p->dado.nome);
    printf("%s\n", p->dado.cpf); 
    p = p->prox;
  }
  printf("\n");
}

/* Procura por um elemento na lista e retorna verdadeiro caso o encontre */

int procuraElementoNaLista(tipoNo *p, char chave[], tipoDadosDePessoas *d) {
  
  while(p) {
    if(strcmp(p->dado.nome,  chave) == 0 ) {
      *d = p->dado;
      return 1;
    }
    p = p->prox;
  }
  return 0;
}



void mostraEnderecosDosElementos(tipoNo *p) {
  
  while(p) {
    printf("%p ", p);
    p = p->prox;
  }
  printf("\n");
}

void CriaLista(tipoNo **p) {
  *p= NULL;
}


int main() {
  int x;
  tipoNo *L1=NULL;
  tipoDadosDePessoas pes;
  char nome[30];  
  
 

  // Aqui para matar a curiosidade sobre tamanho de um no, de um ponteiro e etc...
  printf("Tamanho de um nó da lista %lu\n", sizeof(tipoNo));
  printf("Tamanho de um ponteiro %lu\n",sizeof(tipoNo *)); 
  printf("Tamanho de um int %lu\n",sizeof(int));

  // Agora um for para inserir elementos na lista encadeada L1, 
  // irei transferir do vetor, mas poderia tranqu


 // vou preencher aleatoriamente os dados. Poderia ler os dados no lugar disso
  // Nao tem nenhuma relacao com o assunto de listas encadeadas
  // Pode substituir por uma leitura de dados para o vetor se quiser
  srand(time(NULL));

  for(x = 0; x< 10; x++) {
  preencheAleatoriamente(&pes,1) ;
  insereElemento(&L1,pes);
  }
 // Usando agora a versao 2 da funcao insere, aquela sem ponteiro para ponteiro

 preencheAleatoriamente(&pes,1) ;
 L1 = insereElementoDeOutroJeito(L1,pes);

 //Vamos ver como ficou a lista

 mostraLista(L1);


 // Agora vou ler um nome para procurar na lista. Digite o nome quando executar

 printf("Entre com um nome da lista para buscar seus dados:\n");
 lerString(nome, 30);



 if(procuraElementoNaLista(L1,nome,&pes)==1) {
   printf("Pessoa Encontrada\n");
   printf("****************************\n");
   printf("Nome: %s\nCPF %s\nNumero Interno: %d\n",pes.nome,pes.cpf,pes.numInterno);
   printf("****************************\n");
 }

 // mostraLista(L1);
 // mostraEnderecosDosElementos(L1);


 /* EXERCICIOS:
   Agora:

 1 - mude o programa para pedir que pessoas entrem com dados de mais duas pessoas via teclaco.
 2 - Faça uma funcao que retorne a posicao de um dado nome em uma lista. Se nao encontrar retorna 0. Considere que os nomes comecam na posicao 1.

 3 - Mude o programa para virar um cadastro de produtos de uma lista de compras de um supermercado. Cada item deve conter a descricao do produto, o preco, e o supermercado onde voce o comprou.

  */
}




  
