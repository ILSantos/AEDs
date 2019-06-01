#include <stdio.h>
#include <string.h>
 
 int main(){
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

