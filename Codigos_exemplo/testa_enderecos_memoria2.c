#include<stdio.h>
#include<stdlib.h>

struct no{  
   int id;
   char *nome;
   float valor;
   struct no *prox;
};

int main(){ 
  struct no var_no, segundo_no;

  var_no.id = 1;
  var_no.nome = "aaa";
  var_no.valor = 100.00;
  var_no.prox = NULL;

  printf("id: %d  nome: %s  valor: %f  prox: %p\n", var_no.id, var_no.nome, var_no.valor, var_no.prox);
  printf("prox: %p\n", &var_no.prox);
  printf("end no: %p\n", &var_no);

  segundo_no.id = 2;
  segundo_no.nome = "bbb";
  segundo_no.valor = 150.00;
  segundo_no.prox = NULL;

  var_no.prox = &segundo_no;

  printf("id: %d  nome: %s  valor: %f  prox: %p\n", segundo_no.id, segundo_no.nome, segundo_no.valor, segundo_no.prox);
  printf("prox: %p\n", &segundo_no.prox);
  printf("end no: %p\n", &segundo_no);

  printf("end var_no.prox: %p\n", var_no.prox);

}
