#include <stdio.h>
#include <stdlib.h>

void ordenaSelecao(int v[], int n){
	int i,j;
	int posMenor;
	int tmp;

	for(i = 0; i < n-1; i++){
	  posMenor = i;
	  for(j = i+1; j < n; j++){
		if(v[j] < v[posMenor]){
		  posMenor = j;
		}
	}
	tmp = v[posMenor];
	v[posMenor] = v[i];
	v[i] = tmp;
   }
} 

void ordenaInsercao(int v[], int n){
	int i,j;
	int pivot;
	
	for(i = 1; i < n; i++){
	  pivot = v[i];
	  for(j = i-1; j >= 0; j--){
		if(pivot < v[j]){
		  v[j+1] = v[j];
		 }
		 else {
		   break;
		 }
         }
	   v[j+1] = pivot;
    }
}

void lerVetor(int v[], int n){
	int x;
	
	for(x = 0; x < n; x++){
	  printf("Entre com o valor da posicao v[%d]:", x);
	  scanf("%d", &v[x]);
	} 
}	

void mostraVetor(int v[], int n){
	int x;
	
	for(x = 0; x < n; x++){	
	  printf("%d", v[x]);
	} 
	printf("\n");
}

int quickSort(int v[], int n){
	qSortInterno(v, 0, n-1);
}

void qSortInterno(int v[], int inicio, int fim){
	int pivot;
	int temp;
	int i,j;

	i = inicio;
	j = fim;
	pivot = v[(i+j)/2];

	do{
	  while(v[i] < pivot) i++;
	  while(v[j] > pivot) j--;
	  if(i <= j){
		temp = v[i];
		v[i] = v[j];
		v[j] = temp;
		i++; j--;
	    }
	} 
	while(i <= j);
	
	if(inicio < j) qSortInterno(v, inicio, j);
	if(i < fim) qSortInterno(v, i, fim);	
}


void preencheVetor(int v[], int n){
		
	while(n){
	  n--;
	  v[n] = rand()%100;	
    }
}

int ordenado(int v[], int n){
	int x;
	
	for(x = 0; x < n-1; x++){
	  if(v[x] > v[x+1]){
		return 0;
		}
	}
	return 1;
}


int main(){
	int v[20];
	int k;

	//Nº DE VETORES GERADOS, ORDENADOS E TESTADOS IGUAL A 2000 
	for(k = 0; k < 2000; k++){

	preencheVetor(v,20);
	//mostraVetor(vetor, 20);
	quickSort(v,20);
	if(!ordenado(v,20)){
	  mostraVetor(v,20);
	}
   }
}

