#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[]) {
  FILE *fo,*fd;
  int x; 
  char buffer[1000];


  if(argc != 3) {
    printf("uso: %s <arquivo de origem> <arquivo de destino>\n", argv[0]);
    exit(1);
  }

  fo = fopen(argv[1],"r");
  if(fo == NULL) {
    printf("erro ao abrir arquivo de origem (%s)\n",argv[1]);
    exit(1);
  }

 fd = fopen(argv[2],"w");
  if(fd == NULL) {
    printf("erro ao criar arquivo de destino (%s)\n",argv[2]);
    exit(1);
  }

  do {
    x = fread(buffer,sizeof(char), 1000,fo);
    if(x) {
      fwrite(buffer,sizeof(char),x,fd);
    }
  } while(x==1000);
}
