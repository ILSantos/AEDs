#include <stdio.h>
#include <string.h>


void lerString(char stringVar[], int tamanho) {


  fgets(stringVar,tamanho,stdin);
  if(stringVar[strlen(stringVar)-1] == '\n') {
    stringVar[strlen(stringVar)-1] = 0;
  }

}

void ordenaPorInsercao(char v[], int tamanho) {
  int i, j;
  int pivot;

  for(j = 1; j < tamanho; j++ ) {
    i = j -1;
    pivot = v[j];
    while(i>=0) {
      if(v[i] > pivot) {
	v[i+1]= v[i];
      }
      else {
	break;
      }
      i--;
    }
    v[i+1]= pivot;
  }
}



int main() {
  char nome[20]; //, qualquer[30]="qualquer coisa que eu queira";
  int n;
  int x;
  
  printf("entre com um número:");
  scanf("%d%*c",&n);
  printf("Entre com um nome:");
   lerString(nome,20);
   printf("O tamanho da string digitada é %lu\n",strlen(nome));
   ordenaPorInsercao(nome,strlen(nome));  
   //gets(nome);
  switch(n) {

  case 1:
    printf("voce entrou com o número 1\n");
    printf("o nome digitado foi (%s)\n",nome);
    break;
  case 2:
     printf("voce entrou com o número 2\n");
    printf("o nome digitado foi (%s)",nome);
    printf("os valores da variável nome:\n");
    for(x = 0; x < strlen(nome); x++) {
      printf("nome[%d] = %d\n",x,nome[x]);
    }
    break;
  }

  printf("Veja o codigo ASCII de 48 até 127\n");

  for(x = 48; x < 128; x++) {
    printf("valor %d --> [%c]\n",x,x);
  }

} 
