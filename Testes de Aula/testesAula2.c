#include <stdio.h>
#include <string.h>
#include <stdlib.h>



void lerString(char stringVar[], int tamanho) {


  fgets(stringVar,tamanho,stdin);
  if(stringVar[strlen(stringVar)-1] == '\n') {
    stringVar[strlen(stringVar)-1] = 0;
  }
 
}

int compara( char x, char y) {

  if ((x >= 65) && (x <= 90)) {
    x= x +32;
  }
  return x-y;
}


  void ordenaPorInsercao(char v[][30], int tamanho) {
    int i, j;
    char pivot[30];

    
    for(j = 1; j < tamanho; j++ ) {
      i = j -1;
      strcpy(pivot,v[j]); 
    while(i>=0) {
      if(strcasecmp(v[i],pivot)>0) {
	strcpy(v[i+1],v[i]);
      }
      else {
	break;
      }
      i--;
    }
    strcpy(v[i+1],pivot);
    }
  }

struct tipoDadosDePessoas {
  char nome[30];
  char telefone[15];
  char  cpf[15];
  char observacao[50];
};




int main() {
  int x;
  struct tipoDadosDePessoas K,Outra, Pessoas;
  char vetNomeDePessoas[5][30];

  // lerString(K.nome,30);

  for(x = 0; x< 5; x++) {
    printf("Entre com o nome da posicao %d:",x);
    lerString(vetNomeDePessoas[x],30);
  }
  ordenaPorInsercao(vetNomeDePessoas, 5);
 for(x = 0; x< 5; x++) {
    printf("%s\n",vetNomeDePessoas[x]);
  }
}




  
