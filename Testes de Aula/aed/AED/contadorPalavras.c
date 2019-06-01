#include <stdio.h>
#include <stdlib.h>    // por causa da funcao exit

/***********
Funcao abaixo retorna verdadeiro se o byte passado representa um delimitador. 
 Delimitador é todo símbolo que não faz parte de uma palavra.
 ****************** */

int eDelimitador(char ch) {
  
  if((ch >= 'A') && (ch <= 'Z')) { // de até z nao são delimitadores
    return 0;
  } 
  else  if((ch >= 'a') && (ch <= 'z')) { // de até z nao são delimitadores
    return 0;
  } 
  else if(ch == 0) {  // o fim de string (\0) nao é um delimitador
    return 0;
  }
  else if((ch >= '0') && (ch <= '9')) { // numeros nao sao delimitadores
    return 0;
  }   
  return 1; // não está entre as opções acima, considerei delimitador
}

/* Versao para contar palavras igual ao comando wc do linux. 
Aqui apenas os três simbolos abaixo são considerados delimitadores.*/

/*
int eDelimitador(char ch) {

  if((ch == ' ') || (ch == '\t') || (ch == '\n')) return 1;
  return 0;
}
*/


/* conta o número de palavras de um texto */

int contaPalavras( char *str) {
  int cont = 0;
  
  while(*str) {
    while(eDelimitador(*str)) str++; 
    if(*str) {  // chegou aqui, nao é delimitador, mas pode ser o '\0'
      cont++;   // se chegou aqui, é um inicio de palavra
      while(!eDelimitador(*str) && *str) { // enquanto nao acabar a palavra
	str++;
      }
    }
  }
  return cont;
}


int main(int argc, char *argv[]) {
  FILE *f;
  char linha[1000];
  int cont = 0;
  int contP = 0;
  

  // abaixo abro um arquivo para leitura
  f = fopen(argv[1],"r");

  if (f) {
    while(fgets(linha,1000, f)) {
      cont++;
      printf("%03d: %s",cont, linha);
      contP= contP+ contaPalavras(linha);
      
    }
  }
  else {
    perror("erro de abertura de arquivo. Veja no laboratório o uso de perror");
    printf("Use  o comando man ou busque no web para saber pra que serve perror\n");
    exit(1); // sai do programa indicando que houve erro
  }
  printf("O numero de palavras é %d\n",contP);
}
