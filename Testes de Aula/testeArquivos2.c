#include <stdio.h>

typedef struct {
  char nome[20];
  char endereco[30];
} tipoDadosDeCadastro;


int main() {
  FILE *qualquerNome;
  tipoDadosDeCadastro x;
  int c;


  qualquerNome = fopen("dados.dat","a");
  if(qualquerNome == NULL) {
    qualquerNome = fopen("dados.dat","w");
  }
  for(c = 0; c< 5; c++) {
    printf("Entre com um nome:"); 
    scanf("%s",x.nome);
    printf("Entre com um endereco:"); 
    scanf("%s",x.endereco);
    // Gravar os dados no arquivo
    fwrite(&x,sizeof(tipoDadosDeCadastro),1,qualquerNome);
  }
  fclose(qualquerNome);
}
  
