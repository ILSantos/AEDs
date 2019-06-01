#include<stdio.h>
#define N 3
int main (int vetor[N][N]){
	int x,y;
	int soma = 0;
		
	
	for(x = 0,y = N-1; x < N; x++,y--){
		soma = soma + vetor[x][y];		
			
	}
	prinf("Soma = %s", soma);
	return soma;
 }

