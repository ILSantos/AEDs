#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void mostraMatriz(unsigned char display[8]) {
  int x,y;
  unsigned z;
  system("clear");

  for(x=0; x< 8; x++) {
    for(z = 0x80; z>  0; z = z/2) { 
      if(display[x] & z) {
        printf("1");
      }
      else {
	printf("0");
      }
    }
    printf("\n");
  }

  // getchar();
}

void desloca(unsigned char display[8]) {
 int x;
  for(x=0; x< 8; x++) {
    display[x] = display[x]<<1;
  }
}

void outputLine(unsigned char display[8],unsigned char valor, int linha) {

 display[linha]=valor;
 mostraMatriz(display);
}

int main() {
  unsigned x;
  unsigned char display[8];

 for (x = 0; x < 8; x++) {
   display[x]=0;
  }

  outputLine(display,179,0);
  outputLine(display,255,7);
  for (x = 1; x < 7; x++) {
    outputLine(display,129,x);
  }
  getchar();
  for(x = 0; x< 8; x++) {

    desloca(display);
    mostraMatriz(display);
    getchar();
  }

}
