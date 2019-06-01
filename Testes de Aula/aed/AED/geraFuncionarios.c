#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// AQUI DEFINIMOS CONSTANTES A SEREM USADAS NO PROGRAMA EXEMPLO

#define NUM_ALUNOS 400000
# define NUM_PROFESSORES 400000

// Definicao de um novo tipo de dados para guardar informação sobre pessoas 
// Veja que em uma struct posso misturar diferentes tipos de dados
// posso inclusive ter campos que sao outras structs, caso necessario

typedef struct tipoDadosDePessoas {
  char nome[30];
  float salario;
  int setor;
}  tipoDadosDePessoas ;


// nossa funcao para ler strings com seguranca
void lerString(char stringVar[], int tamanho) {


  fgets(stringVar,tamanho,stdin);
  if(stringVar[strlen(stringVar)-1] == '\n') {
    stringVar[strlen(stringVar)-1] = 0;
  }
 
}



void preencheAleatoriamente(tipoDadosDePessoas v[], int tam) {
  int x,y;
  int tamString;
  char vogais[6]="aeiou";
  char consoantes[22]="bcdfghjklmnpqrstvxyzw";
  int subnome;

  for (x= 0; x < tam; x++) {
    tamString = 10+ rand() % 19;
    subnome = 3+ rand()%4;
    for(y = 0; y < tamString; y++) {
      if(y%subnome == 0) {
	if (y <(tamString-3)) {
	  if(y) {
	    v[x].nome[y]= ' ';
	    y++;
	  }
	  v[x].nome[y] = consoantes[rand()%21]-32;
	  y++;
	}
      }
      if( (y % 2) == 0) {
	v[x].nome[y] = consoantes[rand()%21];
      }
      else {
	v[x].nome[y] = vogais[rand()%5];
      }
      
    }
    v[x].setor = rand();
    v[x].salario = 788.00 + (float) ((float)(rand()%1000000)/100.0);
  }
}

int main() {
  int x;
  tipoDadosDePessoas *vetProfs;

  vetProfs = (tipoDadosDePessoas*) malloc(sizeof(tipoDadosDePessoas)*NUM_PROFESSORES);
  //,vetAlunos[NUM_ALUNOS];
  //tipoDadosDePessoas vetTodos[NUM_ALUNOS+NUM_PROFESSORES]; 
  

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
 
  for(x = 0; x < 10; x++) {
    printf("%s\n%.2f\n%d\n",vetProfs[x].nome,vetProfs[x].salario,vetProfs[x].setor);
  }

 FILE *fp = fopen("arqTeste","w");
 fwrite(vetProfs,sizeof(tipoDadosDePessoas),NUM_PROFESSORES,fp);
 fclose(fp);

 }
 





  
