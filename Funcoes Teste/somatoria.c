#include<stdio.h>

int soma(int n){
	
	int i; 
	int soma = 0;
	
	for (i = 0; i <= n; i++){
		
		soma = soma +(i*i*i);
	}
	
	return soma;
} 

int main(){
	int soma = 0; 
	int i;
	int n;
	
	for (i = 0; i <= n; i++){
		printf("Insira o valor de %d:", i )"\n";
	    printf("Insira o valor de %d:", n );	
		soma = soma +(i*i*i);
	}
	
	return soma;
} 
	
