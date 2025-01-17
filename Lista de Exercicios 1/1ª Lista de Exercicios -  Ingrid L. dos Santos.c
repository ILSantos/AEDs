#include<stdio.h>
#include<math.h>
#include<string.h>

/* 1. Quest�o */
int fatorial (int n){
	
	int fatorial = 1; 
	
	int a;
	
	for (a = n; a > 0; a--){
		fatorial = fatorial * a;
	}
	
	return fatorial;
}

/* 2. Quest�o */
void modifica(int vet[], int tam){
	
		int a; 
		
		for (a = 0; a < tam; a++ ){
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

/* 4. Questao */

int BuscaUfamInString(char *string, char *string2, int tamanho){
	
	int i,j,k;
	int tamanho_2 = strlen(string2);
	
	for(i=0; i < tamanho - tamanho_2 + 2; i++){
		
		if(string[i] == string2[0] || string[i] + 32 == string2[0] || string[i] == string2[0] + 32){
			for(j = 1, k =i+1; j < tamanho_2 && (string[k] == string2[j] || string[k] + 32 == string2[j] || string[k] == string2[j] + 32); j++,k++){
				if(j == tamanho_2-1){
					return 1;
				}
			}
		}
	}
	return 0;
}

/* 5. Quest�o */

int ordcrescente (int vet[], int tam){
	
	int a; 
	
	for (a = 1; a < tam; a++){
		
		if (vet[a] < vet[a-1]){
			return 0;
		}
	}
	
	return 1;
}

/* 6. Quest�o */

void OrdenaPorInsercao(int vet[], int tam){
		
	int a = 1, b, pivot;
		
	while(a < tam){
		pivot = vet[a];
		b = a - 1;
		
		while ((b >= 0) && (pivot < vet[b])){
			vet[a+1] = vet[b];
			b = b - 1;
		}
		
		vet[b + 1] = pivot;
		a++;
	}
}

/* 7. Quest�o */

int QuadradosN(int n){
	
	int result = 0;
	
	while (n > 0){
		result = result + (n*n);
		n = n - 1;
	}
	
	return result;
}

/* 8. Quest�o */

int ContaLetras(char nome[], int tam, char s){
	
	int a; 
	int qntd = 0; 
	char s2;
		
	if(s > 64 && s < 91){
		s2 = s + 32;
	}
	
	if(s > 96 && s > 123){
		s2 = s - 32;
	}
	
	for (a = 0; a < tam; a++){
		if (s == nome[a] ||  s2 == nome[a]){
			qntd = qntd + 1;
		}
	}
	
	return qntd;
}

/* 9. Quest�o */
 int Palindromo(char x[], y[]){
  	
	 char x[100], y[100];
 	
 	printf("Digite um nome: ");
 	gets(x);
 	
 	strcpy (y,x);
 	strrev (y);
 		if (strcmp(x,y) == 0){
 			printf("O nome e um palindrome. \n");
	     }  else{
	 		printf("O nome nao e um palindrome. \n");
	 	 } 
 	
	 return 0;		
 }
 
 /* 10. Questao */
 int umaocorrencia(int vet[], int tam, int chave){
 	
 	int inicio = 0;
 	int fim = tam - 1;
 	int meio, a, vezes = 0;
 	
 	while(inicio <= fim){
 		meio = (inicio + fim)/2;
 		if(chave > vet[meio]){
 			inicio = meio + 1;
 		}
 			else if(chave == vetor[meio]){
 				vezes = vezes + 1;
 				for(a = 1; vet[meio - a] == vet[meio]; a++){
 					vezes = vezes + 1;
 				}
 				for(a = 1, vet[meio + a] == vet[meio]; a++){
 					vezes = vezes + 1;
 				}
 			  break;
 			} 
			  else{ 
 				fim = meio - 1;
 			}
 	}
 	
 	if(vezes == 1){
 		return 1;
 	}
 		else{
 			return 0;
 		}
 }
 
 /* 11. Quest�o */
 
void Diferenca(int vet[], int tam, int delta){
	
	int a;
	
	for(a = 0; a < tam; a++){
		vet[a] = vet[a] - delta;
	}
}

/* 12. Quest�o */

void DiferencaPosicao(int vet[], int tam){
	
	int a; 
	for (a = 1; a < tam; a++){
		vet[a] = vet[a] - vet[a - 1];
	}
}
 
 /* 13. Quest�o */
 
 void InverterEfeito(int vet[], int tam){
 	
 	int a;
 	
 	for(a = 0; a < tam; a++){
 		vet[a] = vet[a] + vet[a - 1];
 	}
 	
 }

/* 14. Quest�o */

/*Temos um vetor de 10 posi��es, sendo essas posi��es de 0 at� 9. A busca se inicia pela 
posi��o que est� no meio do vetor, usando a f�rmula (posicaoinicio + (tam - 1))/2.
Sendo a quarta posi��o do vetor o resultado da primeira busca.

a) O n� 4 ser� comparado com o elemento da posi��o 4 do vetor, sendo esse igual a 40
como 4 � diferente e menor que 40 uma nova busca ir� ocorrer na posi��o central e entre a 
posi��o inicial, sendo 0 a nova posi��o final, uma vez que o antigo valor do meio ser� 
subtraido por 1.
  Na compara��o seguinte o n� 4 ser� comparado com o n� 20 (2� posi��o do vetor), e por ser
diferente e menor que 20 o novo valor final ser� o valor atual do meio subtraido por 1.
 A compara��o seguinte tem o meio como posi��o 0 e o n� 4 ser� comparado com o n� 3 e como 
o n� 4 � maior e diferente de 3 o valor inicial ser� a soma do meio atual mais 1. Encerrando 
assim busca ja que o valor do inicio � maior que o valor final, retornando falso ja que
o valor n�o foi encontrado na busca. 

b) O n� 55 ser� comparado com o n� 40 que est� na 4� posi��o que por ser maior e diferente 
de 40, o meio recebe o valor atual do meio atual somado com 1. Na segunda compara��o o n� 55
ser� comparado com o novo meio, o n� 4, somado com o valor da posi��o final, 9 e dividido 
por 2. Assim comparando o n� 55 com o n� 55 da posi�ao 6, ao se tratar do mesmo valor o 
programa ir� parar e irar retornar o valor verdadeiro um vez que a cahve procurada foi 
encontrada.*/

/* 15. Quest�o */

int QuadradadeK(int n, int matriz[N][N], int K){
	
	int a, b, vezes = 0;
	
	for(b = 0; b < n; b++){
		for (a = 0; a < n; a++){
			if (matriz[a][b] == K){
				vezes = vezes + 1;
			}
		}
		if (vezes == 4){
			return 1;
		} 
	      else{
	      	return 0;
	      }
	}
}


/* 16. Quest�o */

int MaiorElemento(int n int matriz[N][N]){
	
	int a,b, maior = matriz[0][0];
	
	for(a = 0; a < n; a++){
		if( a == 0){
			for(b = 1; b < n; b++){
				if(matriz[a][b] > maior){
					maior = matriz[a][b];
				}
			}
		} else{
				for(b = 0; b < n; b++){
					if(matriz[a][b] > maior){
						maior = matriz[a][b];
					}
				}
		}
	}
	
	return maior;
}

/* 17.Quest�o */

int DiagSecundaria(int n, int matriz[N][N]){
	
		int a, result = 0;
		
		for(a = 0; a < n; a++){
			result = result + matriz[a][n - a - 1];
			 
		}
		
		return result;
}

/* 18. Quest�o */ 

float DesvioPadrao(float vet[], int tam){
	
		int a;
		float media = 0, desvio[tam], variacao = 0; desviop;
		
		for(a = 0; a < tam; a++){
			media = media + vet[a];
		}
		
		media = (media/tam);
		
		for(a = 0; a < tam; a++){
			desvio[a] = (vet[a] - media)*(vet[a] - media);
		}	
		
		for (a = 0; a < tam; a++){
			variacao = variacao + desvio[a];
			
		}
		
		desviop = variacao / tam;
		
		desviop = sqrt(desviop);
		
		return desviop;
}



int main(){
	
	// Teste as fun��es aqui :v 
	
	
	
}

