#include <stdio.h>
#include <string.h>

typedef struct {
  char nome[20];
  char endereco[30];
} tipoDadosDeCadastro;


int main() {
  FILE *qualquerNome;
  tipoDadosDeCadastro x;
  char nome[20];


  qualquerNome = fopen("dados.dat","r");
 
  printf("Entre com um nome a ser buscado:\n");
  scanf("%s",nome);
  while(fread(&x,sizeof(tipoDadosDeCadastro),1,qualquerNome)) {
    if(strcmp(nome,x.nome) == 0) {
      printf("Encontrei!!!!:)\n");
      printf("Nome: %s\n",x.nome);
      printf("Endereco %s\n", x.endereco);
      break;
    }
  }

 fclose(qualquerNome);
}
  
