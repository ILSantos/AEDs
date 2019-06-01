#include<stdio.h>
float fat (int n){
	float r = 1.0;
/* free */ while(n){
		r = r *n;
		n--;
	}
	return r; 
}

float f (int n){
 float soma = 0.0;
 int i;
 
 for (i = 1; i <= n; i++){
 	soma = soma + (i*i*fat(i));
  }
  return soma;
}

int main(){
	int n;
	float d;
	
	d = f(4);
	fat = fatorial(20);
	printf("Entre com um numero:");
	scanf("%d", &n);	
	printf("O resultado  de f quando passo o paramentro %d: %.2f\n",n, f(n));
	printf("O valor de n depois da chamada %d\n",n);
}
