#include <stdio.h>
#include<stdlib.h> 

typedef struct{
	char nome [20];
	char matricula[20];
	char cpf[15];
} tipoDados; 

int main(){
	char x;
	FILE *file;
		
	file = fopen("arqtest", "r");
	
	x = fgetc(file);
	
	while(!feof(file)){
		printf("%c", x);
		x = fgetc(file);
	}
	
}
