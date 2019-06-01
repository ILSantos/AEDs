#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// AQUI DEFINIMOS CONSTANTES A SEREM USADAS NO PROGRAMA EXEMPLO

#define NUM_ALUNOS 4
# define NUM_PROFESSORES 5

// Definicao de um novo tipo de dados para guardar informação sobre pessoas 
// Veja que em uma struct posso misturar diferentes tipos de dados
// posso inclusive ter campos que sao outras structs, caso necessario

typedef struct tipoDadosDePessoas {
  char nome[30];
  int numInterno;
  char  cpf[15];
}  tipoDadosDePessoas ;


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


// Busca Binaria, buscando pelo nome. Assumimos que o vetor esta ordenado pelo nome

int buscaBinaria(tipoDadosDePessoas v[], int tam, char nome[]) {
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
  }
}

int main() {
  int x;
  tipoDadosDePessoas vetProfs[NUM_PROFESSORES],vetAlunos[NUM_ALUNOS];
  tipoDadosDePessoas vetTodos[NUM_ALUNOS+NUM_PROFESSORES]; 

 srand(time(NULL));

  /*
  // VEJA NO FOR ABAIXO O USO DA CONSTANTE
 printf("**** ENTRAR COM DADOS DOS PROFESSORES *****\n");

  for(x = 0; x<  NUM_PROFESSORES; x++) {
    printf("Entre com o nome de professor da posicao %d:",x);
    lerString(vetProfs[x].nome,30);
    printf("Entre com um identificador numerico para o professor:");
    scanf("%d%*c",&vetProfs[x].numInterno);
  }

  printf("**** AGORA ENTRAR COM DADOS DOS ALUNOS *****\n");
  for(x = 0; x<  NUM_ALUNOS; x++) {
    printf("Entre com o nome de aluno da posicao %d:",x);
    lerString(vetAlunos[x].nome,30);
    printf("Entre com um identificador numerico para o aluno:");
    scanf("%d%*c",&vetAlunos[x].numInterno);
  }
  */


  preencheAleatoriamente(vetProfs,NUM_PROFESSORES);
 preencheAleatoriamente(vetAlunos,NUM_ALUNOS);
  // AGORA USAMOS A FUNCAO PARA ORDENAR OS PROFESSORES PELO NOME
  ordenaInsercaoPeloNome(vetProfs, NUM_PROFESSORES);

 // AGORA USAMOS A FUNCAO PARA ORDENAR OS ALUNOS PELO NOME
  ordenaInsercaoPeloNome(vetAlunos, NUM_ALUNOS);
  
  // USANDO O MERGE. VEJA QUE SEI QUE O MERGE cabe em vetTodos!

  merge(vetProfs,NUM_PROFESSORES, vetAlunos, NUM_ALUNOS, vetTodos);

  // MOSTRANDO TODOS OS VETORES

  printf("LISTA DE ALUNOS:\n");
  mostraPessoas(vetAlunos, NUM_ALUNOS);
  printf("LISTA DE PROFESSORES:\n");
  mostraPessoas(vetProfs, NUM_PROFESSORES);
  printf("AGORA MOSTRANDO TODOS ALUNOS E PROFESSORES:\n");
  mostraPessoas(vetTodos,NUM_ALUNOS+NUM_PROFESSORES);
}




  
