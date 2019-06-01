#include <stdio.h>
#include <string.h>

void ordenaPorInsercao(char v[][30], int tamanho){
	int i,j;
	char pivot[30];

	for(j = 1; j < tamanho; j++){
	  i = j-1;
	  strcpy(pivot,v[j]);
	while(i>=0){
	 if(strcasecmp(v[i], pivot)>0){
	   strcpy(v[i+1], v[i]);
	  }
	  else{
		break;
	   }
		i--;
	}
	strcpy(v[i+1], pivot);
  }
}

void ordenaPorInsercao(char v[], int tamanho){
	int i,j;
	int pivot;

	for(j = 1; j < tamanho; j++){
	  i = j -1;
	  pivot = v[j];
	  while(i>=0){
		if(v[i] > pivot){
		  v[i+1] = v[i];
		}
		else{
		 break;
		}
		i--;
	   }
	   v[i+1] = pivot;
	}
}

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

///////////////////////////////////

typedef struct tipoDadosDePessoas{
	char nome[30];
	int numInterno;
	char cpf[15];
} tipoDadosDePessoas; 

// busca binaria, pelo nome.vetor ordenado pelo nome

int buscaBin(tipoDadosDePessoas v[], int tam, char nome[]){
	int meio, inicio = 0, fim = tam-1;
	int tmp;

	while(inicio <= fim){
	meio = (inicio + fim)/2;
	tmp = strcmp(nome, v[nome].nome);
	if(tmp > 0){
		inicio = meio+1;
	}
	else if(tmp < 0){
		fim = meio-1;
	}
	else{
	 return meio;	
	}
   }
	return -1;
} 

// merge entre dois vetores ordenados e resultado inserido em novo vetor
// suponde que ele tenha espaço suficiente 

void merge(tipoDadosDePessoas v1[]
			int n1,
		 tipoDadosDePessoas v2[]
			int n2,
		 tipoDadosDePessoas v3[]){

	int i = 0, j = 0;
	
	while((i < n1) && (j < n2)){
	 if(strcmp(v1[i].nome, v2[j].nome) < 0){
		v3[i+j] = v1[i];
		i++;	
	 }
	 else{
	  v3[i+j] = v2[j];
	  j++;	
	}
   }
	while(j < n2){ v3[i+j] = v2[j]; j++}
	while(i < n1){ v3[i+j] = v1[i]; i++}
}

// Lista Encadeada 

void insereElemento(tipoNo *p, tipoDadosDePessoas elemento){
	tipoNo *aux;
	
	aux = (tipoNo*) malloc (sizeof(tipoNo));
	aux -> prox = p;
	aux -> dado = elemento;
	return aux;
}

void mostraLista(tipoNo *p){
	
	while(p){
	  printf("%s\n", p -> dado.nome);
	  printf("%s\n", p -> dado.cpf);
	  p = p -> prox
	}
	printf("\n");
}

void procuraElementoNaLista(tipoNo *p, char chave[], tipoDadosDePessoas *d){
	
	while(p){
	 if(strcmp(p -> dado.nome, chave)==0){
		*d = p -> dado;
		return 1;
		}
	}
}


