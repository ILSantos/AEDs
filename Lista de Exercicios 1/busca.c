#include<stdio.h>
#include<string.h>


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

int main(){
	
	char string[40];

	int tamanho = strlen(string);
	
	gets(string);
	printf("%d", BuscaUfamInString(string,"UFAM", tamanho));
	
	
}
