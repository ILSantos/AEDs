#include<stdio.h>
#include<stdlib.h>

typedef struct {
char nome[15];
char matricula[15];
char cpf[15];
}tipoDados;



int main (){
char x;
tipoDados d;
FILE *file;
int contPontos = 0;
int contCpf = 0;
int cont = 0;

    file = fopen("arqteste", "r");
    
    x = fgetc(file);
   while(!feof(file)) {
        if(x == ':') {
            contPontos++;
           // printf("%d\n", contPontos);
        }

        if(contPontos == 2) {
         //printf("%d %d %c\n", contPontos, contCpf, x);
            if(contCpf > 0 && contCpf <= 14) {
                printf("%c", x);
            }

            if(contCpf >= 14) {
                contCpf = -1;
                contPontos = 0;
                printf("\n");
	
            }
           // printf(" passou aqui\n");
            contCpf++;
        }

        x = fgetc(file);
        cont++;
   }

	
}
