#include<stdio.h>
#include<math.h>

/* 1. Questão */
int fatorial (int n){
	
	int fatorial = 1; 
	
	int a;
	
	for (a = n; a > 0; a--){
		fatorial = fatorial * a;
	}
	
	return fatorial;
}

/* 2. Questão */
void modifica(int vet[], int tam){
	
		int a; 
		
		for (a = 0; a < tamanho; a++ ){
			if (vet[a] <= 0){
				vet[a] = -2;
				
			}
				else{
					if (vet[a] >= 1 && vet[a] <= 5){
						vet[a] = -1;
					} 
						else{
							vet[a] = 0;
						}
				}
		}
}

/* 3. Questao */
void invertevetor(int vet[], int tam){
		
		int aux, a;
		
		for (a = 0; a < tam; a++){
			aux = vet[a];
			vet[a] = vet[tam - 1 - a];
			vet[tam - 1 - a] = aux;
		}
}
