#include<stdio.h>
#include<stdlib.h>

int x, *pint, tam, i;
char y, *pchar;
float z, *pfloat;
int vetor[1000];
double matrizao[10000][10000];

struct no { 
   int id;
   char nome[40];
   float valor;
   struct no *prox;
 };

struct no var_no;
struct no *ponteiro_no;

int main(){
  x = 2;
  y = 'a';
  z = 1.5;
  pint = &x;
  pchar = &y;
  pfloat = &z;
  printf("endereco conteudo pint: %p\n", pint);
  printf("endereco conteudo pchar: %p\n", pchar);
  printf("endereco conteudo pfloat: %p\n", pfloat);
  printf("endereco pint: %p\n", &pint);
  printf("endereco pchar: %p\n", &pchar);
  printf("endereco pfloat: %p\n", &pfloat);
  tam = sizeof(int);
  printf("tamanho int:%d bytes\n", tam);
  tam = sizeof(char);
  printf("tamanho char:%d byte\n", tam);
  tam = sizeof(float);
  printf("tamanho float:%d bytes\n", tam);
  tam = sizeof(double);
  printf("tamanho double:%d bytes\n", tam);
  tam = sizeof(vetor);
  printf("tamanho vetor:%d bytes\n", tam);
  tam = sizeof(matrizao);
  printf("tamanho matrizao:%d bytes\n", tam);
  tam = sizeof(pint);
  printf("tamanho pint:%d bytes\n", tam);
  tam = sizeof(pchar);
  printf("tamanho pchar:%d bytes\n", tam);
  tam = sizeof(var_no);
  printf("tamanho do no:%d bytes\n", tam);
  tam = sizeof(ponteiro_no);
  printf("tamanho do ponteiro:%d bytes\n", tam);   
  
  return 0;
}
