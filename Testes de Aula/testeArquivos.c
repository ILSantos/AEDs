#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fpInp, *fpOut;
  char nomeArq[200];
  char x;
  printf("Entre com o nome do arquivo de origem:");
  scanf("%s",nomeArq);
  fpInp  = fopen(nomeArq,"r");
  if(fpInp == NULL) {
    printf("Nao consegui abrir o arquivo: %s\n",nomeArq);
    exit(1);
  }


  printf("Entre com o nome do arquivo de destino:");
  scanf("%s",nomeArq);
  fpOut  = fopen(nomeArq,"w");

 if(fpOut == NULL) {
    printf("Nao consegui criar o arquivo: %s\n",nomeArq);
    exit(1);
  }


 while(!feof(fpInp)) {
   x = fgetc(fpInp);
   if(!feof(fpInp)) {
     fputc(x,fpOut);
      }
    }
    fclose(fpInp);
    fclose(fpOut);
}
 

