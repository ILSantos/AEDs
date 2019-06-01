#include<stdio.h>
#define N_5

int main(int vet[]){
	
	int n, i;
	int menor = vet[0];
	int maior = vet[0];
	
	for(i = 1; i < n; i++){
		if(vet[i] >= maior){
			maior = vet[i];
		} 
			else if(vet[i] < menor){
				menor = vet[i];
			}
	}	
	
	return maior + menor;
}
